在草稿纸上列了下 发现了个很棒的规律 ，，就是 不断地拿1 加上 前面的向量里面的值 
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = {0};
        if (num == 0)
            return res;
        int i = 1;
        while(true)
        {
            int len = res.size();
            for (int j = 0; j < len ; j++)
            {
                res.push_back(1 + res[j]);
                i++;
                if(i > num)
                    return res;
            }
        }

    }
};

