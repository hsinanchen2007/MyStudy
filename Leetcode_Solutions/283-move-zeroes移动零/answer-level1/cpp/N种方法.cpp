方法1：暴力双指针法

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        
        for(int i=0; i<nums.size(); i++){//指针1遍历数组
            
            if(nums[i]==0){//如果发现0
                
                for(int j=i+1; j<nums.size(); j++){//指针2遍历剩下的数组
                    
                    if(nums[j]!=0){//找到下一个非0元素

                        
                        //将指针1和指针2的元素互换
                        int temp = nums[j];
     
                        nums[i] += temp;
                        nums[j] -= temp;

                        break;
                    }
                }
            }
        }
        

        

    }
};
```


方法2：利用迭代器

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        
        //利用迭代器遍历数组，删掉所有发现的0，同时记录删掉的0的个数
        for(auto it=nums.begin(); it!=nums.end(), size>0;){
            
            if(*it==0){
                
                it = nums.erase(it);
                nums.push_back(0);
            }
            else
                it++;
            
            
            size--; 
        }
     
    }
};
```


方法3：利用队列

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        queue<int> mark;//用队列来存储可以可以插入的空位
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]==0){
                
                mark.push(i);
            }
            else if(nums[i]!=0 && !mark.empty()){
                
                nums[mark.front()] = nums[i];
                nums[i] = 0;
                mark.pop();
                mark.push(i);
            }
        }
    }
};
```

方法4：简单双指针法

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int mark = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]!=0){
                
                nums[mark] = nums[i];
                mark++;
            }
        }

        for(int i=mark; i<nums.size(); i++){
            
            nums[i]=0;
        }
    }
};
```

方法5：简单双指针法plus

```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int mark = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]!=0){
                
                swap(nums[mark],nums[i]);
                mark++;
            }
        }
    }
};
```
