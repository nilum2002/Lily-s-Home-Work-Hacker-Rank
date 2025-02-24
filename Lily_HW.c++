#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 
 */
 
 
 
 int num_of_swaps(vector<int> arr, vector<int> arr_sotred){
    int swaps = 0;
    // creat an unordered map
    map <int, int> unordered_arr_map;
    for (size_t i = 0 ; i < arr.size(); i++){
        unordered_arr_map[arr[i]] = i;
    }
    // create a visited array with boolian values 
    vector<bool> visited_arr (arr.size(), false);
    
    
    
    for (size_t i = 0; i <arr.size(); i++){
        if (visited_arr[i] || arr[i] == arr_sotred[i]){
            continue;
            
        }
        int cycle_size = 0;
        int j = i;
        while (!visited_arr[j]){
            visited_arr[j] = true ;
            cycle_size ++;
            j = unordered_arr_map[arr_sotred[j]];
        }
        swaps  += cycle_size -1;
    }
    return swaps;
 }

int lilysHomework(vector<int> arr) {
    
    vector <int> arr_sotred = arr;
    sort(arr_sotred.begin(), arr_sotred.end());
    vector <int> reverse_sorted_arr = arr_sotred;
    reverse(arr_sotred.begin(), arr_sotred.end());
    return  min(num_of_swaps(arr, arr_sotred), num_of_swaps(arr, reverse_sorted_arr));

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
