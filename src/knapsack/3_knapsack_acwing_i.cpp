/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

using namespace std;

int main()
{
    int N, V;
    cin>>N>>V;

    int dp[V+1];
    for (int i=0; i<=V; i++) dp[i] = 0;

    for (int i=0; i<N; i++) {
        int v, w, s;
        cin>>v>>w>>s;

        for (int j=V; j>0; j--) {
            for (int k=1; k<=s && k*v<=j; k++) {
                dp[j] = max(dp[j-k*v]+k*w, dp[j]);
            }
        }
    }

    cout << dp[V];

    return 0;
}