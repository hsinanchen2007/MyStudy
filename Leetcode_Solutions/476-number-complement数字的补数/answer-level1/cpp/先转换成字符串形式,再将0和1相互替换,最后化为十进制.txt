```
class Solution {
public:
    int findComplement(int num) 
    {
        string str;
        while (num != 0)
        {
            char temp = num % 2 + '0';
            str.push_back(temp);
            num = num / 2;
        }
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++)
        {
            str[i] == '0' ? str[i] = '1': str[i] = '0';
        }
        int result = stoi(str, 0, 2);

        cout << result;
        return result;
    }
};
```
