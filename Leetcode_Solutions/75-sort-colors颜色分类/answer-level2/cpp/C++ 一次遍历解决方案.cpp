### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void swap(vector<int>::iterator a, vector<int>::iterator b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
void sortColors(vector<int>& nums) {
    auto beg = nums.begin();
    auto end = nums.end()-1;
    int one_counter = 0;
    int two_counter = 0;

    for(auto i = nums.begin(); i!=nums.end(); ++i){

        if(*i==0){
            if((beg+one_counter)!=i){
                swap(beg+one_counter, i);
                one_counter++;
                i--;
            }


        }
        else if(*i == 2&&(end-two_counter)!=i){
            swap(end-two_counter, i);
            two_counter++;
            i--;
        }
        if(i == (end-two_counter)) break;
    }

}
};
```