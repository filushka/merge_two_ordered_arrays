/*
merge_two ordered_array -- this program merges two ordered arrays into one ordered array
Copyright (C) <2016>  <Elena Filenko>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

///
/// \brief merge_two_ordered_arrays
/// \param arr_1 -- pointer to the first array
/// \param size_1 -- size of the first array
/// \param arr_2 -- pointer to the second array
/// \param size_2 -- size of the second array
/// \param arr_res -- array where result of sorted merge of two arrays places
///
void merge_two_ordered_arrays( int* arr_1, int size_1, int* arr_2, int size_2, int* arr_res )
{
    int i = 0;
    int j = 0;
    int cur_index = 0;

    while( i < size_1 && j < size_2 )
    {
        if( arr_1[ i ] < arr_2[ j ] )
        {
            arr_res[ cur_index ] = arr_1[ i ];
            ++i;
        }
        else if( arr_1[ i ] == arr_2[ j ]  )
        {
            arr_res[ cur_index ] = arr_1[ i ];
            ++cur_index;
            arr_res[ cur_index ] =  arr_2[ j ];
            ++i;
            ++j;
        }
        else
        {
            arr_res[ cur_index ] = arr_2[ j ];
            ++j;
        }

        ++cur_index;
    }

    if( i == size_1 )
        memcpy( arr_res + cur_index, arr_2 +j, (size_2 -j)*sizeof(int) );

    if( j == size_2 )
       memcpy( arr_res + cur_index, arr_1 +i, (size_1 - i) * sizeof(int) );

}

int main(int argc, char *argv[])
{
    int arr_res[ 200 ] = { 0 };

    // Test 1
    {
        int arr_1[ ] = { 10,20,30,40,50,60,70,80, 90 };
        int arr_2[] = { 10,20,30,40,50,60,70,80, 90 };

        merge_two_ordered_arrays( arr_1, 9, arr_2, 9, arr_res );

        for( int i = 0; i < 18; i++ )
            cout << arr_res[ i ] << ", ";

        cout << endl << endl;
    }

    // Test 2
    {
        int arr_1[ ] = { 10,20,30,40,50,60,70,80 };
        int arr_2[] = { 10,21,33,46,51,60,70,99,99,108 };

        merge_two_ordered_arrays( arr_1, 8, arr_2, 10, arr_res );

        for( int i = 0; i < 18; i++ )
            cout << arr_res[ i ] << ", ";

        cout << endl << endl;
    }

    // Test 3
    {
        int arr_1[ ] = { 10,20,30,40,50,60,70,80, 80 };
        int arr_2[] = { 3,5,11,19,46,51,60,70,80 };

        merge_two_ordered_arrays( arr_1, 9, arr_2, 9, arr_res );

        for( int i = 0; i < 18; i++ )
            cout << arr_res[ i ] << ", ";

        cout << endl << endl;
    }

    // Test 4
    {
        int arr_1[ ] = { 10,20,30,40,50,60,70,80, 80, 90, 100, 110 };
        int arr_2[] = { 30, 40, 41, 42, 45, 46, 87 };

        merge_two_ordered_arrays( arr_1, 11, arr_2, 7, arr_res );

        for( int i = 0; i < 18; i++ )
            cout << arr_res[ i ] << ", ";

        cout << endl << endl;
    }

    // Test 5
    {
        int arr_1[ ] = { 10,20 };
        int arr_2[] = { 87 };

        merge_two_ordered_arrays( arr_1, 2, arr_2, 1, arr_res );

        for( int i = 0; i < 3; i++ )
            cout << arr_res[ i ] << ", ";

        cout << endl << endl;
    }

    return 0;
}
