构造节点：用于排序后面的写入值
```
typedef struct node
{
    int index;
    int val;
    bool operator()(struct node& t1, struct node& t2){
        return t1.val > t2.val;    //<会产生升序排序,若改为>,则变为降序
    }
}NODE;
```
代码：
```
typedef struct node
{
    int index;
    int val;
    bool operator()(struct node& t1, struct node& t2){
        return t1.val > t2.val;    //<会产生升序排序,若改为>,则变为降序
    }
}NODE;
class Solution {
public:
    string Gold   = {"Gold Medal"};
    string Silver = {"Silver Medal"};
    string Bronze = {"Bronze Medal"};
    vector<string> findRelativeRanks(vector<int>& nums) {
        list<NODE> value;
        NODE tmp_node;
        vector<string> ret_string(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            tmp_node.index = i;
            tmp_node.val   = nums[i];
            value.push_back(tmp_node);
        }
        value.sort(node());
        
        int i = 1;
        for (list<NODE>::iterator it = value.begin(); it != value.end(); it++) {
            if (i < 4) {
                switch (i) {
                    case 1: ret_string[(*it).index] = Gold;   break;
                    case 2: ret_string[(*it).index] = Silver; break;
                    case 3: ret_string[(*it).index] = Bronze; break;
                }
            }else{
                ret_string[(*it).index] = to_string(i);
            }
            ++i;
        }

        return ret_string;
    }
};
```














