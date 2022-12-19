这是一道非常典型的题目，值得我们细细研究。题意十分简单，在一个数组nums[]中找到满足三数之和为0的所有情况，将它们保存在一个vector<vector<int> >类型的变量中返回。直观来看，用暴力解法分析，用三个for循环遍历所有可能性，代码看起来如下：
```
int len = nums.size();
for(int i=0; i<len-2; i++){
    for(int j=i+1; j<len-1;j++){
        for(int k=j+1; k<len; k++){
            if(nums[i] + nums[j] + nums[k] == 0){
                vector<int > vtemp{nums[i],nums[j],nums[k]};
                ret.push_back(vtemp);
            }
        }
    }
}
```
不难分析出此暴力算法的时间复杂度为O(n^3),这显然是不能通过所有的case的，而且上述算法还有一个错误，没有去重。这题的一大难点，除了时间复杂度需要满足要求外，还需要对结果去重。举个例子分析如下，我们考虑数组nums[] = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6],显然，仅仅按照下标循环时，会出现多个[-4,2,2],多个[-4,0,4],多个[-2,-2,4],多个[-2,0,2]等。题目要求我们去重。

如果我们对有序数组中求两数和为定值的算法熟悉的话，我们会很快找到正确的思路。array[]是一个从小到大有序排列的数组，找出数组中所有两数之和为定值target的数对。这本质是一个搜索问题，因为我们必须遍历数组，把所有可能情况考虑进去，当然，用两个for循环能用O(n^2)的时间复杂度完成目标，但是这就没有利用到数组是有序的特点。其实，我们可以从数组的两端同时进行搜索，这就是双指针的由来。具体算法看起来如下：
```
//array = [1,2,3,4,5,6,7,8,9]; array is sorted in a increasing order
//target = 10;
int len = array.size();
int p1 = 0, p2 = len - 1; //p1 points to the start of the array and p2 points to the end
//the search stops when the two pointers meet each other
while(p1 < p2){
    if(array[p1] + array[p2] < target){
        p1++;
    }else if(array[p1] + array[p2] == target){
        cout << p1 << p2 << endl;
        p1++,p2--;
    }else{
        p2--;
    }

}
```
以上就是双指针寻找有序数组中两数和为定值的算法，解释如下：当array[p1] + array[p2] < target时，下一步调整的目标是要使左边的式子增大。由于p1从左往右搜索，array[p1]增大，p2从右往左搜索，array[p2]减小，则使左边的式子增大的唯一可能是p1右移，即p1++；另外，注意到，当出现一个满足array[p1] + array[p2] == target的情况时，p1左边的任何位置，或p2右侧的任何位置处均不可能出现满足搜索条件的值(左侧总是小于,右侧总是大于)。同理可知，当array[p1] + array[p2]  = 或 > 时的指针移动情况。由于p1,p2相遇时正好相当于遍历了一次有序数组，所以算法时间复杂度为O(n)。

受双指针寻找有序数组中两数和为定值算法的启发，我们可以将这个三数和问题转化为两数和问题，但先要进行排序(O(nlogn))，然后循环选定一个数(O(n))，在这个数后面的区间里寻找两数和为定值的数组(O(n))，算法整体的时间复杂度为O(n^2)。代码如下：
```
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int > vtemp;
        int len = nums.size();
        sort(nums.begin(),nums.end());//sort the input
        for(int i=0;i<len-2;i++){
            //find the tripe for each nums[i]
            // j1 and j2 log the index of the other two numbers
            if(i ==0 ||(i>0 && nums[i] != nums[i-1])){
                int p1 = i+1, p2 = len-1; // set two pointers
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    }else if(nums[p1] + nums[p2] == -nums[i]){
                        if(p1 == i+1){
                            vector<int > vtemp{nums[i], nums[p1], nums[p2]};
                            ret.push_back(vtemp);
                            vtemp.clear();

                        }else if(nums[p1] != nums[p1-1]){
                            vector<int > vtemp{nums[i], nums[p1], nums[p2]};
                            ret.push_back(vtemp);
                            vtemp.clear();

                        }
                        p1++,p2--;
                    }else{
                         p2--;
                    }
                }
            }


        }
        return ret;

    }
};
```
算法中最难的一部分，是去重问题，如前面分析的，题目要求返回不重复的triple，这就要求在搜索时注意技巧。最终返回三个数，对于每个数，如果其等于它上个位置的数值时，(数组的有序性保证了相等数的相邻性)，它便不能存入返回vector中，即代码中增加的if判断条件。

至此，我们比较完整的解决了这个搜索三数和的问题，主要利用了双指针算法及去重的技巧。




