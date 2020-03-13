/*
 * A sample prefetcher which does sequential one-block lookahead.
 * This means that the prefetcher fetches the next block _after_ the one that
 * was just accessed. It also ignores requests to blocks already in the cache.
 */
// This garbage is written in c++98

#include "interface.hh"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void print_stat(AccessStat stat)
{
    printf("PC:%d\nmem_addr:%d\ntime:%d\nmiss:%d\n\n", stat.pc, stat.mem_addr, stat.time, stat.miss);
}

void prefetch_init(void)
{
    /* Called before any calls to prefetch_access. */
    /* This is the place to initialize data structures. */


    // Added comment to see if Alberto can commit
    //DPRINTF(HWPrefetch, "Initialized sequential-on-access prefetcher\n");
    printf("Hello prefetch init, printf!\n");
    std::cout << __cplusplus << std::endl;
}

void prefetch_access(AccessStat stat)
{
    printf("Hello prefetch access, printf!\n");
    print_stat(stat);
    //DPRINTF(HWPrefetch, "We are in the prefetch access\n");
    /* pf_addr is now an address within the _next_ cache block */
    Addr pf_addr = stat.mem_addr + BLOCK_SIZE;

    /*
     * Issue a prefetch request if a demand miss occured,
     * and the block is not already in cache.
     */
    if (stat.miss && !in_cache(pf_addr)) {
        issue_prefetch(pf_addr);
    }
}

void prefetch_complete(Addr addr) {
    DPRINTF(HWPrefetch, "We are in the prefetch complete\n");
    fprintf(stderr, "Hello prefetch complete, standard err!\n");
    printf("Hello prefetch complete, regular printf!\n");
    /*
     * Called when a block requested by the prefetcher has been loaded.
     */
}
