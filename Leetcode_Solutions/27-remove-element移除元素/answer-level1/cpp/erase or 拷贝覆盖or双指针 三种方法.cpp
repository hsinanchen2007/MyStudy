一、erase
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=nums.size();
        for(vector<int>::iterator it=nums.begin();it!=nums.end();){
            if(*it==val){
                it=nums.erase(it);
                res--;
            }
            else if(*it==val&&*(it+1)!=val) break;
            else it++;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0504e52c62ceed335183b233fe0d1279961fda9f7460c2026752dc5f55b39a3d-image.png)
二、拷贝覆盖
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tmp=0;
        for(auto num:nums){
            if(num!=val){
                nums[tmp]=num;
                tmp++;
            }
        }
        return tmp;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5e5f320cfcaaf1263fd78ebc7b63a3b25c8935959abe1983fa47a93425cdbbdb-image.png)
方法三：快慢指针
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res=nums.size();
        int i=0,j=0;
        for(;j<res;){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
                j++;
            }
            else j++;
        }
        return res+i-j;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8e644d56fdfd7654358ff62ea4c09912cc5d6b7c0f4f76b19784e4f41453cb83-image.png)



