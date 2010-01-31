/*
 *  The implementation of hash_map_t and hash_multimap_t test.
 *  Copyright (C)  2008,2009,2010  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

/** include section **/
#include "chash_map.h"
#include "cfunctional.h"
#include "test_hashtable.h"
#include "test_hash_map.h"

/** local constant declaration and local macro section **/

/** local data type declaration and local struct, union, enum section **/

/** local function prototype section **/

/** exported global variable definition section **/

/** local global variable definition section **/

/** exported function implementation section **/
void test_hash_map(void)
{
    /* c built-in type */
    {
        /*create_hash_map            */
        /*hash_map_init              */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init(pt_hmap);
            pair_init(pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            pair_make(pt_pair, 45, 42304.23);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 1029, 22.2);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 0, 0.20);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_init_ex           */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 100, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            pair_make(pt_pair, 45, 42304.23);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 1029, 22.2);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 0, 0.20);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_init_copy         */
        {
            hash_map_t* pt_hmap = create_hash_map(short, int);
            hash_map_t* pt_hmapex = create_hash_map(short, int);
            pair_t* pt_pair = create_pair(short, int);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init(pt_hmapex);
            pair_init(pt_pair);

            pair_make(pt_pair, 45, 1023);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 0, 234);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, -9, -3235);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 23, 23);
            hash_map_insert(pt_hmapex, pt_pair);

            hash_map_init_copy(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmapex, "<%hd, %d>, ", short, int);
            _print_hash_map_c(pt_hmap, "<%hd, %d>, ", short, int);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_init_copy_range   */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            pair_init(pt_pair);
            hash_map_init_ex(pt_hmapex, 100, _hash_map_int_key_hash, NULL);

            pair_make(pt_pair, 23, 434.239);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 2, 1.0);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 445, 34.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 6, 2.9);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 4, 213);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 0, 42.2);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 2, 234.09);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 3, 20.123);
            hash_map_insert(pt_hmapex, pt_pair);

            hash_map_init_copy_range(pt_hmap, hash_map_begin(pt_hmapex),
                hash_map_end(pt_hmapex));
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_init_copy_range_ex*/
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init(pt_hmapex);
            pair_init(pt_pair);

            pair_make(pt_pair, 3, 43.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 12, 12.12);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 0, 2.0);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 9, 9.0);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 121, 23.2);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 1, 23.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 8, 2.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 3, 45.09);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_init_copy_range_ex(pt_hmap, hash_map_begin(pt_hmapex),
                hash_map_end(pt_hmapex),
                100, _hash_map_int_key_hash, NULL);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_destroy           */
        /*hash_map_assign            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            pair_make(pt_pair, 23, 290.233);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, -7, -7.7);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 0, 0.0);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 112122, 3.23);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            pair_make(pt_pair, 9, 434.345);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 23, 23.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 9, 232323.2323);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 1, 43.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 6, 6.6);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 5, 23.2323);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 4, 232.0);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            pair_make(pt_pair, 34, 23.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 6, 34.1);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_swap              */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            pair_make(pt_pair, 23, 290.233);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, -7, -7.7);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 0, 0.0);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 112122, 3.23);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            pair_make(pt_pair, 9, 434.345);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 23, 23.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 9, 232323.2323);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 1, 43.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 6, 6.6);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 5, 23.2323);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 4, 232.0);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            pair_make(pt_pair, 34, 23.23);
            hash_map_insert(pt_hmapex, pt_pair);
            pair_make(pt_pair, 6, 34.1);
            hash_map_insert(pt_hmapex, pt_pair);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmapex);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_size              */
        /*hash_map_empty             */
        /*hash_map_max_size          */
        /*hash_map_bucket_count      */
        /*hash_map_hash              */
        /*hash_map_key_less          */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 100, _hash_map_int_key_hash, fun_great_int);
            assert(hash_map_hash(pt_hmap) == _hash_map_int_key_hash &&
                hash_map_key_less(pt_hmap) == fun_great_int);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_resize            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init(pt_hmap);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_resize(pt_hmap, 50);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_resize(pt_hmap, 500);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_resize(pt_hmap, 5);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_resize(pt_hmap, 0);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_equal             */
        /*hash_map_not_equal         */
        /*hash_map_less              */
        /*hash_map_less_equal        */
        /*hash_map_great             */
        /*hash_map_great_equal       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            pair_make(pt_pair, 4, 89.23);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            hash_map_insert(pt_hmapex, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            pair_make(pt_pair, 2, 90.2);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 3, 2323.23423);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 10, 10.0);
            hash_map_insert(pt_hmapex, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_begin             */
        /*hash_map_end               */
        /*hash_map_find              */
        /*hash_map_count             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            iterator_t t_iter;
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            pair_make(pt_pair, 0, 0.0);
            t_iter = hash_map_find(pt_hmap, 0);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 0));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 0));
            }

            pair_make(pt_pair, 45, 23.232);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 23, 1.111);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 56, 23.2222);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 0, 0.0);

            t_iter = hash_map_find(pt_hmap, 0);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 0));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 0));
            }

            pair_make(pt_pair, 45, 23.232);
            t_iter = hash_map_find(pt_hmap, 45);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 45));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 45));
            }

            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_equal_range       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            range_t t_range;
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            t_range = hash_map_equal_range(pt_hmap, 0);
            assert(iterator_equal(t_range.t_begin, hash_map_end(pt_hmap)) &&
                iterator_equal(t_range.t_begin, t_range.t_end));

            pair_make(pt_pair, 3, 290.2323);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 67, 34.11);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 5, 333.222);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 14, 44.4);
            hash_map_insert(pt_hmap, pt_pair);
            t_range = hash_map_equal_range(pt_hmap, 0);
            assert(iterator_equal(t_range.t_begin, t_range.t_end));
            t_range = hash_map_equal_range(pt_hmap, 14);
            assert(iterator_equal(iterator_next(t_range.t_begin), t_range.t_end));

            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_at                */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            printf("%lf\n", *(double*)hash_map_at(pt_hmap, 8));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            pair_make(pt_pair, 4, 232.222);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 0, 2.222);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 9, 12.111);
            hash_map_insert(pt_hmap, pt_pair);

            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            *(double*)hash_map_at(pt_hmap, 0) = 0.0;
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_insert            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            pair_make(pt_pair, 23, 0.983);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 4, 90.0);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 2, 2.22);
            hash_map_insert(pt_hmap, pt_pair);
            pair_make(pt_pair, 4, -83784.2323);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_insert_range      */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            hash_map_t* pt_hmapex = create_hash_map(int, double);
            pair_t* pt_pair = create_pair(int, double);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_int_key_hash, NULL);
            pair_init(pt_pair);

            hash_map_insert_range(pt_hmap, hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            *(double*)hash_map_at(pt_hmapex, 45) = 4.34;
            *(double*)hash_map_at(pt_hmapex, 2) = -4.245;
            *(double*)hash_map_at(pt_hmapex, 56) = 34.23;
            *(double*)hash_map_at(pt_hmapex, 3) = 3.3;
            *(double*)hash_map_at(pt_hmapex, 0) = 0.0;
            *(double*)hash_map_at(pt_hmapex, 343) = 5.5634;
            *(double*)hash_map_at(pt_hmapex, 22) = 22.22;
            *(double*)hash_map_at(pt_hmapex, 5) = 5.5555;
            *(double*)hash_map_at(pt_hmapex, 4) = 10.1;
            *(double*)hash_map_at(pt_hmapex, 334) = -0.000003;
            *(double*)hash_map_at(pt_hmapex, 44) = 44.44;
            *(double*)hash_map_at(pt_hmapex, 1) = 1.1;
            _print_hash_map_c(pt_hmapex, "<%d, %lf>, ", int, double);

            hash_map_insert_range(pt_hmap, hash_map_begin(pt_hmapex), hash_map_begin(pt_hmapex));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_insert_range(pt_hmap, hash_map_begin(pt_hmapex),
                iterator_advance(hash_map_begin(pt_hmapex), 3));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_insert_range(pt_hmap, iterator_advance(hash_map_begin(pt_hmapex), 5),
                iterator_advance(hash_map_begin(pt_hmapex), 7));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_insert_range(pt_hmap, iterator_advance(hash_map_begin(pt_hmapex), 9),
                hash_map_end(pt_hmapex));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_insert_range(pt_hmap, hash_map_end(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_clear(pt_hmap);
            hash_map_insert_range(pt_hmap, hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_erase             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_erase(pt_hmap, 0);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            *(double*)hash_map_at(pt_hmap, 45) = 4.34;
            *(double*)hash_map_at(pt_hmap, 2) = -4.245;
            *(double*)hash_map_at(pt_hmap, 56) = 34.23;
            *(double*)hash_map_at(pt_hmap, 3) = 3.3;
            *(double*)hash_map_at(pt_hmap, 0) = 0.0;
            *(double*)hash_map_at(pt_hmap, 343) = 5.5634;
            *(double*)hash_map_at(pt_hmap, 22) = 22.22;
            *(double*)hash_map_at(pt_hmap, 5) = 5.5555;
            *(double*)hash_map_at(pt_hmap, 4) = 10.1;
            *(double*)hash_map_at(pt_hmap, 334) = -0.000003;
            *(double*)hash_map_at(pt_hmap, 44) = 44.44;
            *(double*)hash_map_at(pt_hmap, 1) = 1.1;
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_erase(pt_hmap, 10);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase(pt_hmap, 22);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_erase_pos         */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            *(double*)hash_map_at(pt_hmap, 45) = 4.34;
            *(double*)hash_map_at(pt_hmap, 2) = -4.245;
            *(double*)hash_map_at(pt_hmap, 56) = 34.23;
            *(double*)hash_map_at(pt_hmap, 3) = 3.3;
            *(double*)hash_map_at(pt_hmap, 0) = 0.0;
            *(double*)hash_map_at(pt_hmap, 343) = 5.5634;
            *(double*)hash_map_at(pt_hmap, 22) = 22.22;
            *(double*)hash_map_at(pt_hmap, 5) = 5.5555;
            *(double*)hash_map_at(pt_hmap, 4) = 10.1;
            *(double*)hash_map_at(pt_hmap, 334) = -0.000003;
            *(double*)hash_map_at(pt_hmap, 44) = 44.44;
            *(double*)hash_map_at(pt_hmap, 1) = 1.1;
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_erase_pos(pt_hmap, hash_map_begin(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_pos(pt_hmap, iterator_advance(hash_map_begin(pt_hmap), 3));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            while(!hash_map_empty(pt_hmap))
            {
                hash_map_erase_pos(pt_hmap, hash_map_begin(pt_hmap));
            }
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_erase_range       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            *(double*)hash_map_at(pt_hmap, 45) = 4.34;
            *(double*)hash_map_at(pt_hmap, 2) = -4.245;
            *(double*)hash_map_at(pt_hmap, 56) = 34.23;
            *(double*)hash_map_at(pt_hmap, 3) = 3.3;
            *(double*)hash_map_at(pt_hmap, 0) = 0.0;
            *(double*)hash_map_at(pt_hmap, 343) = 5.5634;
            *(double*)hash_map_at(pt_hmap, 22) = 22.22;
            *(double*)hash_map_at(pt_hmap, 5) = 5.5555;
            *(double*)hash_map_at(pt_hmap, 4) = 10.1;
            *(double*)hash_map_at(pt_hmap, 334) = -0.000003;
            *(double*)hash_map_at(pt_hmap, 44) = 44.44;
            *(double*)hash_map_at(pt_hmap, 1) = 1.1;
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap), hash_map_begin(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap),
                iterator_advance(hash_map_begin(pt_hmap), 3));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_range(pt_hmap, iterator_next(hash_map_begin(pt_hmap)),
                iterator_advance(hash_map_begin(pt_hmap), 4));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_range(pt_hmap, iterator_advance(hash_map_begin(pt_hmap), 3),
                hash_map_end(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_range(pt_hmap, hash_map_end(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_clear             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, double);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_int_key_hash, NULL);
            hash_map_clear(pt_hmap);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);
            *(double*)hash_map_at(pt_hmap, 45) = 4.34;
            *(double*)hash_map_at(pt_hmap, 2) = -4.245;
            *(double*)hash_map_at(pt_hmap, 56) = 34.23;
            *(double*)hash_map_at(pt_hmap, 3) = 3.3;
            *(double*)hash_map_at(pt_hmap, 0) = 0.0;
            *(double*)hash_map_at(pt_hmap, 343) = 5.5634;
            *(double*)hash_map_at(pt_hmap, 22) = 22.22;
            *(double*)hash_map_at(pt_hmap, 5) = 5.5555;
            *(double*)hash_map_at(pt_hmap, 4) = 10.1;
            *(double*)hash_map_at(pt_hmap, 334) = -0.000003;
            *(double*)hash_map_at(pt_hmap, 44) = 44.44;
            *(double*)hash_map_at(pt_hmap, 1) = 1.1;
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_clear(pt_hmap);
            _print_hash_map_c(pt_hmap, "<%d, %lf>, ", int, double);

            hash_map_destroy(pt_hmap);
        }
    }
    /* user define type */
    {
        type_register(hash_sample_t, _hash_sample_init, _hash_sample_copy,
            _hash_sample_less, _hash_sample_destroy);
        /*create_hash_map            */
        /*hash_map_init              */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init(pt_hmap);
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmap, 34))->_l_second = 4509;
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_init_ex           */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmap, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmap, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 90))->_l_second = 90;
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_init_copy         */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_l_second = 90;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;

            hash_map_init_copy(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_init_copy_range   */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_l_second = 90;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmapex);

            hash_map_init_copy_range(pt_hmap,
                hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_init_copy_range_ex*/
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init(pt_hmapex);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_l_second = 90;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmapex);

            hash_map_init_copy_range_ex(pt_hmap,
                hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex),
                0, _hash_map_sample_hash, NULL);
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_destroy           */
        /*hash_map_assign            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_l_second = 90;

            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);

            hash_map_clear(pt_hmapex);
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_l_second = 50;

            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);

            hash_map_clear(pt_hmapex);
            ((hash_sample_t*)hash_map_at(pt_hmapex, 100))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 100))->_l_second = 50;
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);

            hash_map_clear(pt_hmapex);
            hash_map_assign(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_swap              */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_d_first = 43.4;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 34))->_l_second = 4509;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_d_first = -1.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 90))->_l_second = 90;

            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);

            hash_map_clear(pt_hmapex);
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_l_second = 50;

            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);

            hash_map_clear(pt_hmapex);
            ((hash_sample_t*)hash_map_at(pt_hmapex, 100))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 100))->_l_second = 50;
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);

            hash_map_clear(pt_hmapex);
            hash_map_swap(pt_hmap, pt_hmapex);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_size              */
        /*hash_map_empty             */
        /*hash_map_max_size          */
        /*hash_map_bucket_count      */
        /*hash_map_hash              */
        /*hash_map_key_less          */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, fun_great_int);
            assert(hash_map_hash(pt_hmap) == _hash_map_sample_hash &&
                hash_map_key_less(pt_hmap) == fun_great_int);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_resize            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init(pt_hmap);
            _print_hash_map_sample(pt_hmap);
            hash_map_resize(pt_hmap, 70);
            _print_hash_map_sample(pt_hmap);
            hash_map_resize(pt_hmap, 100);
            _print_hash_map_sample(pt_hmap);
            hash_map_resize(pt_hmap, 30);
            _print_hash_map_sample(pt_hmap);
            hash_map_resize(pt_hmap, 0);
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_equal             */
        /*hash_map_not_equal         */
        /*hash_map_less              */
        /*hash_map_less_equal        */
        /*hash_map_great             */
        /*hash_map_great_equal       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            hash_sample_t t_sample;
            pair_t* pt_pair = create_pair(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL || pt_pair == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);
            pair_init(pt_pair);

            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            t_sample._d_first = 89.23;
            t_sample._l_second = -11002244;
            pair_make(pt_pair, 4, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            hash_map_insert(pt_hmapex, pt_pair);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            t_sample._d_first = 90.2;
            t_sample._l_second = 5555555;
            pair_make(pt_pair, 2, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            t_sample._d_first = 2323.2323;
            t_sample._l_second = -10101010;
            pair_make(pt_pair, 3, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            t_sample._d_first = 10.0;
            t_sample._l_second = 10;
            pair_make(pt_pair, 10, &t_sample);
            hash_map_insert(pt_hmapex, pt_pair);
            _print_hash_map_sample(pt_hmap);
            _print_hash_map_sample(pt_hmapex);
            printf("equal: %d, not equal: %d, ",
                hash_map_equal(pt_hmap, pt_hmapex), hash_map_not_equal(pt_hmap, pt_hmapex));
            printf("less: %d, less equal: %d, ",
                hash_map_less(pt_hmap, pt_hmapex), hash_map_less_equal(pt_hmap, pt_hmapex));
            printf("great: %d, great equal: %d\n",
                hash_map_great(pt_hmap, pt_hmapex), hash_map_great_equal(pt_hmap, pt_hmapex));

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
            pair_destroy(pt_pair);
        }
        /*hash_map_begin             */
        /*hash_map_end               */
        /*hash_map_find              */
        /*hash_map_count             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            iterator_t t_iter;
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            t_iter = hash_map_find(pt_hmap, 0);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 0));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 0));
            }

            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;

            t_iter = hash_map_find(pt_hmap, 0);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 0));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 0));
            }
            t_iter = hash_map_find(pt_hmap, 9);
            if(iterator_equal(t_iter, hash_map_end(pt_hmap)))
            {
                printf("not found! count : %u\n", hash_map_count(pt_hmap, 9));
            }
            else
            {
                printf("found! count : %u\n", hash_map_count(pt_hmap, 9));
            }

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_equal_range       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            range_t t_range;
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            t_range = hash_map_equal_range(pt_hmap, 0);
            assert(iterator_equal(t_range.t_begin, hash_map_end(pt_hmap)) &&
                iterator_equal(t_range.t_begin, t_range.t_end));
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            t_range = hash_map_equal_range(pt_hmap, 0);
            assert(iterator_equal(t_range.t_begin, t_range.t_end));
            t_range = hash_map_equal_range(pt_hmap, 56);
            assert(iterator_equal(iterator_next(t_range.t_begin), t_range.t_end));

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_at                */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 500000;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -0.00001;
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_insert            */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            pair_t* pt_pair = create_pair(int, hash_sample_t);
            hash_sample_t t_sample;
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            pair_init(pt_pair);
            _print_hash_map_sample(pt_hmap);
            t_sample._d_first = 90.2;
            t_sample._l_second = 5555555;
            pair_make(pt_pair, 2, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            t_sample._d_first = 2323.2323;
            t_sample._l_second = -10101010;
            pair_make(pt_pair, 3, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            t_sample._d_first = 10.0;
            t_sample._l_second = 10;
            pair_make(pt_pair, 10, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            t_sample._d_first = 10.110;
            t_sample._l_second = 1011;
            pair_make(pt_pair, 10, &t_sample);
            hash_map_insert(pt_hmap, pt_pair);
            _print_hash_map_sample(pt_hmap);
            
            hash_map_destroy(pt_hmap);
            pair_destroy(pt_pair);
        }
        /*hash_map_insert_range      */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            hash_map_t* pt_hmapex = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL || pt_hmapex == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_init_ex(pt_hmapex, 0, _hash_map_sample_hash, NULL);
            hash_map_insert_range(pt_hmap,
                hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_sample(pt_hmap);

            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 6))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 6))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 4))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 4))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 19))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 19))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 86))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 86))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 7))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 7))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 3))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 3))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmapex, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmapex);

            hash_map_insert_range(pt_hmap,
                hash_map_begin(pt_hmapex), hash_map_begin(pt_hmapex));
            _print_hash_map_sample(pt_hmap);
            hash_map_insert_range(pt_hmap,
                hash_map_begin(pt_hmapex), iterator_advance(hash_map_begin(pt_hmapex), 3));
            _print_hash_map_sample(pt_hmap);
            hash_map_insert_range(pt_hmap,
                iterator_advance(hash_map_begin(pt_hmapex), 5),
                iterator_advance(hash_map_begin(pt_hmapex), 7));
            _print_hash_map_sample(pt_hmap);
            hash_map_insert_range(pt_hmap, iterator_advance(hash_map_begin(pt_hmapex), 8),
                hash_map_end(pt_hmapex));
            _print_hash_map_sample(pt_hmap);
            hash_map_insert_range(pt_hmap, hash_map_end(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_sample(pt_hmap);

            hash_map_clear(pt_hmap);
            hash_map_insert_range(pt_hmap, hash_map_begin(pt_hmapex), hash_map_end(pt_hmapex));
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
            hash_map_destroy(pt_hmapex);
        }
        /*hash_map_erase             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_erase(pt_hmap, 0);
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmap);
            hash_map_erase(pt_hmap, 0);
            _print_hash_map_sample(pt_hmap);
            hash_map_erase(pt_hmap, 7);
            _print_hash_map_sample(pt_hmap);
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_erase_pos         */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_pos(pt_hmap, hash_map_begin(pt_hmap));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_pos(pt_hmap, iterator_advance(hash_map_begin(pt_hmap), 4));
            _print_hash_map_sample(pt_hmap);
            while(!hash_map_empty(pt_hmap))
            {
                hash_map_erase_pos(pt_hmap, hash_map_begin(pt_hmap));
            }
            _print_hash_map_sample(pt_hmap);
            while(!hash_map_empty(pt_hmap))
            hash_map_destroy(pt_hmap);
        }
        /*hash_map_erase_range       */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap, hash_map_begin(pt_hmap), hash_map_begin(pt_hmap));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap,
                hash_map_begin(pt_hmap), iterator_advance(hash_map_begin(pt_hmap), 3));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap,
                iterator_next(hash_map_begin(pt_hmap)),
                iterator_advance(hash_map_begin(pt_hmap), 3));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap,
                iterator_advance(hash_map_begin(pt_hmap), 2), hash_map_end(pt_hmap));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap,
                hash_map_end(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_sample(pt_hmap);
            hash_map_erase_range(pt_hmap,
                hash_map_begin(pt_hmap), hash_map_end(pt_hmap));
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
        }
        /*hash_map_clear             */
        {
            hash_map_t* pt_hmap = create_hash_map(int, hash_sample_t);
            if(pt_hmap == NULL)
            {
                return;
            }
            hash_map_init_ex(pt_hmap, 0, _hash_map_sample_hash, NULL);
            hash_map_clear(pt_hmap);
            _print_hash_map_sample(pt_hmap);
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 9))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 6))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 4))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 19))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 86))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 7))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 3))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 56))->_l_second = 50;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_d_first = -5.11;
            ((hash_sample_t*)hash_map_at(pt_hmap, 54))->_l_second = 50;
            _print_hash_map_sample(pt_hmap);
            hash_map_clear(pt_hmap);
            _print_hash_map_sample(pt_hmap);

            hash_map_destroy(pt_hmap);
        }
    }
    /* cstl built-in type */
    {
    }
    /* c-string type */
    {
    }

    /*create_hash_map            */
    /*hash_map_init              */
    /*hash_map_init_ex           */
    /*hash_map_init_copy         */
    /*hash_map_init_copy_range   */
    /*hash_map_init_copy_range_ex*/
    /*hash_map_destroy           */
    /*hash_map_assign            */
    /*hash_map_swap              */
    /*hash_map_size              */
    /*hash_map_empty             */
    /*hash_map_max_size          */
    /*hash_map_bucket_count      */
    /*hash_map_hash              */
    /*hash_map_key_less          */
    /*hash_map_resize            */
    /*hash_map_equal             */
    /*hash_map_not_equal         */
    /*hash_map_less              */
    /*hash_map_less_equal        */
    /*hash_map_great             */
    /*hash_map_great_equal       */
    /*hash_map_begin             */
    /*hash_map_end               */
    /*hash_map_find              */
    /*hash_map_count             */
    /*hash_map_equal_range       */
    /*hash_map_at                */
    /*hash_map_insert            */
    /*hash_map_insert_range      */
    /*hash_map_erase             */
    /*hash_map_erase_pos         */
    /*hash_map_erase_range       */
    /*hash_map_clear             */
}

void test_hash_multimap(void)
{
}

/** local function implementation section **/

/** eof **/

