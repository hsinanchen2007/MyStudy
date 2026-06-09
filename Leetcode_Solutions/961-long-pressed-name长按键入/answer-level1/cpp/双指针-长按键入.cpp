遍历typed:
1.判断当前typed与当前name是否相同
2.如1不成立，判断与前一个name字符是否相同
3.如若2不成立返回false
由于两个string的有效字符长度会不同，需要判断
    

    bool isLongPressedName(string name, string typed) {
        int j = 0, len = name.size();
        for(int i = 0; i < typed.size(); i++)
        {
            if(typed[i] == name[j] && j < len)
            {
                j++;
                continue;
            }
            else if(j > 0 && typed[i] == name[j-1]) //首字母不同时j-1超出索引范围
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        if (j == len)
            return true;
        else
            return false;
    }


