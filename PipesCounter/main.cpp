#include <iostream>
#include <vector>

using namespace std;

bool equality(const vector<vector<int>>& a,const vector<vector<int>>& b){
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[i].size();j++){
                if (a[i][j]!=b[i][j])
                {
                    return false;
                }
        }
    }
    return true;
}
/**
 * Implement function getResult
 */
 int findNeighbors(const vector<string>& matrix,int i,int j){

     vector<vector<int>> mat{{0,0,0},{0,0,0},{0,0,0}};
     if (matrix[i][j]=='1') {
         if (i + 1 == matrix.size()) {
             mat[mat.size() - 1][1] = 1;
         } else if (matrix[i + 1][j] == '1') {
             mat[1 + 1][1] = 1;
         }
         if (i - 1 == -1) {
             mat[0][1] = 1;
         } else if (matrix[i - 1][j] == '1') {
             mat[1 - 1][1] = 1;
         }
         if (j + 1 == matrix[i].size()) {
             mat[1][mat[i].size() - 1] = 1;
         } else if (matrix[i][j + 1] == '1') {
             mat[1][1 + 1] = 1;
         }
         if (j - 1 == -1) {
             mat[1][0] = 1;
         } else if (matrix[i][j - 1] == '1') {
             mat[1][1 - 1] = 1;
         }
         if (j - 1 == -1 && i - 1 == -1) {
             mat[0][0] = 1;
         } else if (matrix[i][j - 1] == '1') {
             mat[1][1 - 1] = 1;
         }
     }
   // vector<vector<int>> pipe21{{0,0,0},{0,0,1},{0,0,0}};
   // vector<vector<int>> pipe21_1{{0,0,0},{1,0,0},{0,0,0}};
    vector<vector<int>> pipe21_2{{0,0,0},{1,0,1},{0,0,0}};
    vector<vector<int>> pipe29{{0,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> pipe32{{0,0,0},{1,0,1},{0,1,0}};
    vector<vector<int>> pipe63{{0,1,0},{1,0,1},{0,1,0}};
    vector<vector<int>> pipe40{{0,1,0},{0,0,1},{0,1,0}};
    vector<vector<int>> pipe31{{0,1,0},{1,0,0},{0,1,0}};
    vector<vector<int>> pipe10{{0,0,0},{1,0,0},{0,1,0}};
    vector<vector<int>> pipe13{{0,1,0},{1,0,0},{0,0,0}};
    vector<vector<int>> pipe17{{0,0,0},{0,0,1},{0,1,0}};
    vector<vector<int>> pipe20{{0,1,0},{0,0,0},{0,1,0}};
    if (equality(mat,pipe20))
    {
        return 20;
    }
    if (equality(mat,pipe21_2))
    {
        return 21;
    }
    if (equality(mat,pipe29))
    {
        return 29;
    }
    if (equality(mat,pipe32))
    {
        return 32;
    }
    if (equality(mat,pipe63))
    {
        return 63;
    }
    if (equality(mat,pipe40))
    {
        return 40;
    }
    if (equality(mat,pipe31))
    {
        return 31;
    }
    if (equality(mat,pipe10))
    {
        return 10;
    }
    if (equality(mat,pipe13))
    {
        return 13;
    }
    if (equality(mat,pipe17))
    {
        return 17;
    }
    if (equality(mat,pipe20))
    {
        return 20;
    }
return 0;
 }
int getResult(vector<string> scheme)
{
    vector<string> filtredScheme{};
    for(int i = 0;i<scheme.size();i++) {
        string row;
        for (int j = 0; j < scheme[i].size(); j++) {
            if (scheme[i][j] != '-') {
                row+=scheme[i][j];
            }

        }
        filtredScheme.push_back(row);
    }
    int result = 0;
    for(int i = 0;i<filtredScheme.size();i++){
        for (int j=0;j<filtredScheme[i].size();j++) {

    result += findNeighbors(filtredScheme, i, j);
}

    }
    cout<<result;
    return result;
}

int main()
{
    vector<string>scheme{
    "0-0-0-0",
            "1-1-1-0",
            "0-0-1-0",
            "0-0-1-0"};
    vector<string> filtredScheme{};
    for(int i = 0;i<scheme.size();i++) {
        string row;
        for (int j = 0; j < scheme[i].size(); j++) {
            if (scheme[i][j] != '-') {
                row+=scheme[i][j];
            }

        }
        filtredScheme.push_back(row);
    }
    getResult(filtredScheme);
    // Entrypoint to debug your function
}