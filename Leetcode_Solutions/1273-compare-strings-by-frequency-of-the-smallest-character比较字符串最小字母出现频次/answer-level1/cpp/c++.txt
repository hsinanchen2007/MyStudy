```
//1.先求出两个字符串数组每个字符串的f(s)存放在两个vector(temp1,t2mp2)中
    vector<int>temp1, temp2;
    //对字符串数组queries求f(s)
    for (int i = 0; i < queries.size(); i++)
    {
        int n = 0;
        sort(queries[i].begin(), queries[i].end());
        for (int j = 0; j < queries[i].size(); j++)
        {
            if (queries[i][j] == queries[i][0])
            {
                n++;
            }
        }
        temp1.push_back(n);
    }
    //对字符串数组words求f(s)
    for (int i = 0; i < words.size(); i++)
    {
        int n = 0;
        sort(words[i].begin(), words[i].end());
        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] == words[i][0])
            {
                n++;
            }
        }
        temp2.push_back(n);
    }
    //2.再对所求的temp1和temp2进行大小比较,对temp1里面每个数,求temp2中比它大的数的个数存放在result中
    vector<int> result;
    for (int i = 0; i < temp1.size(); i++)
    {
        int n = 0;
        for (int j = 0; j < temp2.size(); j++)
        {
            if (temp1[i] < temp2[j])
            {
                n++;
            }
        }
        result.push_back(n);
        cout << n << endl;
    }
    return result;
```
