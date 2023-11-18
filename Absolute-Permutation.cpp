#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */


vector<int> absolutePermutation(int n, int k)
{
    vector<int> result;

    if (k == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            result.emplace_back(i);
        }
    }
    else if (n % 2 == 0 && n % (k * 2) == 0)
    {
        for (int i = 1, j = 1; i <= n; ++i)
        {
            result.emplace_back((j++ <= k) ? i + k : i - k);

            if (j > k * 2)
            {
                j = 1;
            }
        }
    }
    else
    {
        result.emplace_back(-1);
    }

    return result;
}

vector<int> absolutePermutation2(int n, int k) {
    vector<int> result;

    if (k != 0)
    {
        if (n % 2 == 1)
        {
            return { -1 };
        }

        if (n % 2 == 0 && n % (k*2) == 0 )
        {
            int j = 1;

            for (int i = 1; i <= n; ++i)
            {
                if (j <= k)
                {
                    result.emplace_back(i+k);
                }
                else
                {
                    result.emplace_back(i-k);
                }

                j++;
                
                if (j > k*2)
                {
                    j = 1;
                }
            }

            return result;
        }
        else
        {
            return {-1};
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            result.emplace_back(i);
        }
        
        return result;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
