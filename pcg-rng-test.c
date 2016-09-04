/*
 * Testing PCG Random Number Generation.
 *
 * Cayetano Benavent 2016.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "pcg-c-basic/pcg_basic.h"


int main(int argc, char** argv)
{

    int seedinitseq;
    int n_iters;

    if ( argc >= 2 ) {
        seedinitseq = atoi( argv[1] );
    }
    else {
        seedinitseq = 0;
    }

    pcg32_random_t rng;
    pcg32_srandom_r(&rng, time(NULL) ^ (intptr_t)&printf,(intptr_t)&seedinitseq);

    if ( argc >= 3 ) {
        n_iters = atoi( argv[2] );
    }
    else {
        n_iters = 1;
    }

    int i;
    for ( i=0; i<n_iters; i++ ){

        printf("#Iteration: %d", i+1);
        printf("\n");

        printf("0x%08x", pcg32_random_r(&rng));
        printf("\n");

        printf("%d", pcg32_random_r(&rng));
        printf("\n");

        printf("%f", (double)pcg32_random_r(&rng)*0.00000001);
        printf("\n");

        printf("%c", pcg32_boundedrand_r(&rng, 2) ? 'A' : 'B');
        printf("\n");

        printf("%d", pcg32_boundedrand_r(&rng, 2) ? 1 : -1);
        printf("\n");

        printf("%d", (int32_t)pcg32_boundedrand_r(&rng, 100));
        printf("\n");
        printf("\n");
    }

    return 0;
}
