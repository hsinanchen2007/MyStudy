    public bool IsAnagram(string s, string t) {

        // 前提： 异为词 字母相同，但顺序不同
        //【思路】先将 s 的次放入字典中，key为对于的字符串，value为该字符出现的次数
        // 然后遍历t，如果在dict中不存在字符，则直接返回false，如果存在，且数量大于1，则
        // 将字段中该字符的数量减一，如果为1，则将该字符从字典中剔除
        if(s.Length!=t.Length)
            return false;
        Dictionary<char,int> dict = new Dictionary<char, int>();
        for(int i=0;i<s.Length;i++) {
            if(dict.ContainsKey(s[i])) {
                dict[s[i]]++;
            }else
                dict.Add(s[i],1);
        }

        for(int i=0;i<t.Length;i++) {
            if(dict.ContainsKey(t[i])) {
                if(dict[t[i]]!=1) {
                    dict[t[i]]--;
                }else {
                    dict.Remove(t[i]);
                }
            }else
                return false;
        }
        return true;
    }