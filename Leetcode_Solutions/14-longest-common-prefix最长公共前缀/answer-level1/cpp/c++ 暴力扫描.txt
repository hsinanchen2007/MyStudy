```
        int size = strs.size();
        if (size == 0)
        {
            return "";
        }
        int min = strs[0].size();
        for (int i = 0; i < size; i++)
        {
            if (min < strs[i].size())
            {
                min = strs[i].size();
            }
        }
        string data{""};
        for (int i = 0; i < min; i++)
        {
            char tmp = strs[0][i];
            for (int j = 0; j < size; j++)
            {
                if (tmp != strs[j][i])
                {
                    return data;
                }
            }
            data.push_back(tmp);
        }
        return data;
```
