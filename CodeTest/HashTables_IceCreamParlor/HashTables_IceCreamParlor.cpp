#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

#include <unordered_map>

void PrintLowerToUpper(int A, int B)
{
	int LowerValue = 0;
	int UpperValue = 0;

	if (A > B)
	{
		LowerValue = B;
		UpperValue = A;
	}
	else
	{
		LowerValue = A;
		UpperValue = B;
	}

	std::cout << LowerValue << " " << UpperValue << std::endl;
}

void whatFlavors(vector<int> cost, int money)
{
	std::unordered_multimap<int, int> FilteringCost;

	int Cost_Size = static_cast<int>(cost.size());
	for (int i = 0; i < Cost_Size; i++)
	{
		if (cost[i] < money)
		{
			FilteringCost.insert(std::make_pair(cost[i], i + 1));
		}
	}

	for (const std::pair<int, int>& _CurPair : FilteringCost)
	{
		int _CurMoney = _CurPair.first;
		int _PairMoney = money - _CurMoney;
		if (_CurMoney == _PairMoney)
		{
			std::pair<std::unordered_multimap<int, int>::iterator, std::unordered_multimap<int, int>::iterator> Range = FilteringCost.equal_range(_CurMoney);
			std::unordered_multimap<int, int>::iterator SecondRange = ++Range.first;

			if (SecondRange == Range.second)
			{
				continue;
			}

			PrintLowerToUpper(_CurPair.second, SecondRange->second);
			return;
		}
		else if (FilteringCost.end() != FilteringCost.find(_PairMoney))
		{
			PrintLowerToUpper(_CurPair.second, FilteringCost.find(_PairMoney)->second);
			return;
		}
	}
}


int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
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
