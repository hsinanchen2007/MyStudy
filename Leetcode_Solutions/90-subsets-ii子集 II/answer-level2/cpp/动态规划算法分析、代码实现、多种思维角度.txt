（一）动态规划思想解题
算法描述：
    1）申请一个vector<vector<int>>型数组subset_set,并将空数组{}push_back进去；
    2）调用库函数对nums数组从小到大排序；
    3）设置一个变量用以累计某个nums元素重复的次数，初始化为1（每次遇到相同的元素就累加1，直到遇到不同的元素时重新归1，以便下一个重复元素的累计。未重复的元素对应的k总是1）；
    4）遍历Nums数组 for i=0 to nums的size减1：
         若为第一个元素：
             此时subset_set中只有空集一个子集，只需先将空集复制一份push_back到subset_set中，                           再将 nums[i]push_back到subset_set的最后一个元素的末尾；
         否则：
             判断nums[i]!=nums[i-1]:
                 此时先将归1；
                 然后遍历当前的subset_set：
                     将每个子集复制一份push_back到subset_set中,然后将nums[i]添加到该末尾的
                     子集中；
             否则:
                 k累加1；
                 因为下面要判断subset_set中每个子集的末尾元素是等于当前元素nums[i]，所以需要对空子                          集专门处理：先复制一份push_back到subset_set，再循环k次把k个nums[i]添加到该子集的末尾；
                 遍历subset_set数组中不含元素nums[i]的子集（前面push子集时都把新子集添加到末尾，所                          以，实际上遍历的是前面的不含nums[i]的子集，又因为每个子集形成时都是把当时的新元素                           放到子集的末尾，所以只需要遍历地比较nums[i]与每个子集的末尾元素)，直到遇到含nums[i]                         的子集退出循环；
                    循环中要做与对空子集类似的处理；
     返回最终结果subset_set；                
例如：
![图片3.png](https://pic.leetcode-cn.com/c525ff7d289713e6f9bdd80bf1db86336eb4d783fda39c9e917d87b6986c4bc8-%E5%9B%BE%E7%89%873.png)

代码实现如下：
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>subset_set;//保存在中结果
        subset_set.push_back({});     //先把子集push进去
        sort(nums.begin(),nums.end());//处理前对nums数组从小到大排序
        int k=1;                      //用以记录某个元素重复的次数
        for(int i=0;i<nums.size();i++){//遍历nums数组，进行求解
            if(i==0){                  //因为需要比较前后两项是否相等，所以对nums                                          第一个元素要例外处理：
                subset_set.push_back(subset_set[i]);
                subset_set.back().push_back(nums[i]);                
            }
            else{                      //从nums数组第二个数组开始 ，先比较再处理
                if(nums[i]!=nums[i-1]){//不相等时，直接处理
                    k=1;//
                    int n=subset_set.size();
                    for(int j=0;j<n;j++){
                        subset_set.push_back(subset_set[j]);
                        subset_set.back().push_back(nums[i]);                 
                    }
                }
                else{                  //遇到了重复的元素，要特殊处理
                    k++;               //重复数字要累加
                    subset_set.push_back(subset_set[0]);//这三行对首位的空子集进行处理
                    for(int j=1;j<=k;j++){
                        subset_set.back().push_back(nums[i]);  
                    }
                    int p=1;           //遍历subset_set中的子集，并进行处理，直到遇到子                                        //集中含有重复的元素为止
                    while(subset_set[p].back()!=nums[i]){
                        subset_set.push_back(subset_set[p]);
                        for(int j=1;j<=k;j++){ //这个循环用于对一个子集一次次那个添加k                                                //个重复元素
                            subset_set.back().push_back(nums[i]); 
                        }
                        p++;
                    }
                }
            }
        }
        return subset_set;
    }
};
```

运行结果：一次提交中 12ms,90.90%;9.4MB,58.56%.


（二）由78题可知，也可从分治、回溯等角度设计算法，都可以迭代或递归地设计成程序。众网友已做过很多工作，不再赘述。