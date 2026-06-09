### 解题思路
1、使用multiset的自动排序功能
2、在滑动窗口的时候就把中位数的指针找到
3、时间复杂度为O(n)

### 代码

```cpp
class Solution {
public:
    multiset<int> slide_window_set;
    multiset<int>::iterator it_median;
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0 || k > nums.size()){
            vector<double> res;
            return res;
        }

        int size = nums.size();
        vector<double> res;
        double median;
        
        median = initSlideWindow(nums,k);
        res.push_back(median);

        for(int i = k;i < size;i++){
            addElementToSet(nums[i]);
            deleteElementFromSet(nums[i-k]);
            res.push_back(getMedian(k));
        }

        return res;
    }

    double initSlideWindow(vector<int> & nums, int k) {
        for(int i = 0;i < k;i++){
            addElementToSet(nums[i]);
        }
        double median = getMedian(k);
        return median;
    }

    double getMedian(int k) {//获取中位数
        if(k % 2 == 1){//k是奇数
            return *it_median;
        }

        return 0.5 * ((double)*it_median + (double)*next(it_median));//k是偶数
    }

    void addElementToSet(int num) {//向窗口中增加一个元素，根据滑动窗口的size以及当前指针指向的元素和新插入的元素的大小来移动中位数指针
        slide_window_set.insert(num);
        int size = slide_window_set.size();
        if(size == 1){
            it_median = slide_window_set.begin();
        }else if(((size % 2) == 1) && (*it_median <= num)){//
            it_median++;
        }else if(((size % 2) == 0) && (*it_median > num)){
            it_median--;
        }
    }

    void deleteElementFromSet(int num) {//从串口中删除一个值，此处注意erase的用法，其参数必须是指针（迭代器）；根据滑动窗口的size以及当前指针指向的元素和新插入的元素的大小来移动中位数指针
        int size = slide_window_set.size();
        //首先看存在与否
        auto it = slide_window_set.find(num);
        if(it == slide_window_set.end()){
            return;
        }

        if(size % 2 == 1){
            if(*it_median < num || it == it_median){
                it_median--;
            }
        }else{
            if(*it_median >= num || it == it_median){
                it_median++;
            }
        }
        slide_window_set.erase(it);
    }
};

/*暴力法会超时
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0 || k > nums.size()){
        vector<double> res;
        return res;
    }

    int size = nums.size();
    vector<double> res(size - k + 1);
    vector<int> sub_nums(k);

    for(int i = 0;i < (size - k + 1);i++){
        getSubnums(nums,k,i,sub_nums);
        sort(sub_nums.begin(),sub_nums.end(),cmp);
        
//        cout<<"*****BEGIN*****"<<endl;
//        for(int i = 0;i < k;i++){
//            cout<<"1111 sub_nums[" + to_string(i) + "] = " + to_string(sub_nums[i])<<endl;
//        }
//        cout<<"*****END*****"<<endl;
//        
        double median = 0;
        if(k % 2 == 0){
            median = medianSlidingWindow_even(sub_nums,k);
        }else{//奇数时
            median = medianSlidingWindow_odd(sub_nums,k);
        }
        res[i] = median;
    }


    return res;
    }


    double medianSlidingWindow_odd(vector<int>& s_nums, int k){//奇数
        return  s_nums[((k-1)/2)];
    }

    double medianSlidingWindow_even(vector<int> & s_nums, int k) {//偶数
        int left = (k/2) - 1;
        int right = (k/2);
        return ((double)s_nums[left] + (double)s_nums[right]) / 2;
    }

    void getSubnums(vector<int> &nums, int k, int i,vector<int> &sub_nums) {
        vector<int> res(k);
        for(int j = i;j < (i + k);j++){
//            cout<<"0000 getSubnums nums[" + to_string(j) + "] = " + to_string(nums[j])<<endl;
            sub_nums[j-i] = nums[j];
        }
    }

    static bool cmp(const int &a,const int &b){
        return a<b;
    }

};

*/
```