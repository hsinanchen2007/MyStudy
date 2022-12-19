1.利用unordered_map统计每个字母出现的次数
2.构建一个结构体
```
   struct pair{
        int times;
        char letter;
    };
```
3.将map中的数据转为结构体后传入一个数组中
4.利用sort函数对pair.times 排序
5.按照排好的顺序创建新的string



```
class Solution {
private:
    struct pair{
        int times;
        char letter;
    };

    static bool compare(pair a, pair b){ //自定义排序方式
        if (a.times >= b.times)
            return true;
        else
            return false;
    }
public:

    string frequencySort(string s) {

        unordered_map<char, int> record1;
        for (auto letter : s) //利用unordered_map统计每个字母出现的次数
            record1[letter] ++;

        vector<pair> record2;
        pair x;
        for (auto pairOfrecord : record1 ){ //将map中的数据转为结构体后传入一个数组中
            x.letter = pairOfrecord.first;
            x.times = pairOfrecord.second;
            record2.push_back(x);
        }

        sort(record2.begin(), record2.end(), compare);//利用sort函数对pair.times 排序

        string result = "";
        for (auto pairOfrecord2 : record2) {//按照排好的顺序创建新的string
            for (int i = 0; i < pairOfrecord2.times; ++i) {
                result += pairOfrecord2.letter;
            }
        }

        return result;
    }
};
```

