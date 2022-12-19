
1. 假如给定若干字符，例如A,B,C,D的数量分别为a,b,c,d. 若要求全量使用这些字符，根据数学排列组合知识，计算输出总数F(abcd)表示如下:
F(abcd) = C(a,a+b+c+d)*C(b,b+c+d)*C(c,c+d)*C(d,d) = a!b!c!d!/(a+b+c+d)!
其中，abcd分别表示一个数字，如A,B,C,D的个数分别为1,1,2,2，表示为F(1122)
2. 于是，可以把题目分解，先求出所有的子集，再根据1的方法求总数
3. 由于题目只要求输出总数，不需要像全排列那样列举，故可以将子集合并，如AAB与CCB都可表示为F(12)

```
class Solution {
public:
    int numTilePossibilities(string tiles) {
        //统计各个字符出现的次数
        vector<char> char_vec;
        vector<int> count_vec;
        for(char c: tiles) {
            int i = 0;
            for(; i < char_vec.size(); i++) {
                if(char_vec.at(i) == c) {
                    count_vec.at(i)++;
                    break;
                }
            }
            if(i == char_vec.size()) {
                char_vec.push_back(c);
                count_vec.push_back(1);
            }
        }
        int len = count_vec.size();
        //获取子集，type_vec.at(index)表示对应字符的个数
        //模拟数学进位，type_vec.at(index)最大为count_vec.at(index)
        vector<int> type_vec(len, 0);
        //key:子集key value:子集出现的次数
        unordered_map<int, int> key2count;
        while(true) {
            //待加一的位，为-1表示已满
            int index = len - 1;
            while(index != -1 && type_vec.at(index) == count_vec.at(index)) {
                type_vec.at(index) = 0;
                index--;
            }
            if(index == -1) {
                break;
            }
            type_vec.at(index)++;
            int num = getKey(type_vec);
            key2count[num]++;
        }
        int total = 0;
        for(const auto& [type, count]: key2count) {
            total += getCount(type) * count;
        }
        return total;
    }

private:
    //由type_vec获取key，用于去重
    int getKey(const vector<int>& type_vec) {
        vector<int> temp;
        for(int num: type_vec) {
            if(num != 0) {
                temp.push_back(num);
            }
        }
        sort(temp.begin(), temp.end());
        int key = 0;
        for(int num: temp) {
            key = key * 10 + num;
        }
        return key;
    }
    //由key获取单个子集排列组合总数
    int getCount(int key) {
        vector<int> temp;
        while(key != 0) {
            temp.push_back(key % 10);
            key /= 10;
        }
        int index_up = 1, index_down = 1;
        int count = 0;
        for(int num: temp) {
            count += num;
            for(int i = 2; i <= num; i++) {
                index_down *= i;
            }
        }
        for(int i = 2; i <= count; i++) {
            index_up *= i;
        }
        return index_up / index_down;
    }
};
```
