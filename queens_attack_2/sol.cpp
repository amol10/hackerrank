#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    //ofstream dout(getenv("OUTPUT_PATH"));

    //total attack positions
    int total_atk_pos = 0;
    //left hor
    total_atk_pos += c_q - 1;
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //left upper diag
    int possible_diag = c_q - 1;
    int diag = n - r_q;
    int effective_diag = min(possible_diag, diag);
    total_atk_pos += effective_diag;
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //upper vert
    total_atk_pos += n - r_q;
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //right upper diag
    possible_diag = n - c_q;
    effective_diag = min(possible_diag, diag);
    total_atk_pos += effective_diag;
    //right hor
    total_atk_pos += n - c_q;
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //right lower diag
    possible_diag = r_q - 1;
    diag = n - c_q;
    total_atk_pos += min(possible_diag, diag);
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //lower  vert
    total_atk_pos += r_q - 1;
    cout << "DEBUG: tap = " << total_atk_pos << "\n";
    //lower left diag
    diag = c_q - 1;
    total_atk_pos += min(possible_diag, diag);
    cout << "DEBUG: tap = " << total_atk_pos << "\n";

    cout << "DEBUG: total attack positions = " << total_atk_pos << "\n";

    //left hor
    int closest_c = -1;
    for (int i = 0; i < k; i++) {
        int r = obstacles[i][0];
        int c = obstacles[i][1];
        if (r == r_q) {
            if (c > closest_c) {
                closest_c = c;
            }
        }
    }

    //dout.close();
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    fout << "hello";

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
