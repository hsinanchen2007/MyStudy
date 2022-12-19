### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    double cal_ans(vector<int>& nums1, vector<int>& nums2, int cut1, int cut2) {
        if((nums1.size()+nums2.size())%2==0){
            if(cut1==0&&cut2==nums2.size()) return (nums2[cut2-1]+nums1[cut1]) / 2.0;
            if(cut2==0&&cut1==nums1.size()) return (nums1[cut1-1]+nums2[cut2]) / 2.0;
            if(cut1==0) return (nums2[cut2-1]+min(nums1[cut1],nums2[cut2])) / 2.0;
            if(cut2==0) return (nums1[cut1-1]+min(nums1[cut1],nums2[cut2])) / 2.0;
            if(cut1==nums1.size()) return (max(nums1[cut1-1], nums2[cut2-1])+nums2[cut2]) / 2.0;
            if(cut2==nums2.size()) return (max(nums1[cut1-1], nums2[cut2-1])+nums1[cut1]) / 2.0;
            else return (max(nums1[cut1-1], nums2[cut2-1])+min(nums1[cut1], nums2[cut2])) / 2.0;
        }
        else{
            if(cut1==0) return nums2[cut2-1];
            if(cut2==0) return nums1[cut1-1];
            else return max(nums1[cut1-1], nums2[cut2-1]);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size();
        int s2=nums2.size();
        if(nums1.size()==0){
            if(s2%2==0){
                return (nums2[s2/2] + nums2[s2/2-1]) / 2.0;
            }else return nums2[s2/2] + 0.0;
        }
        if(nums2.size()==0){
            if(s1%2==0){
                return (nums1[s1/2] + nums1[s1/2-1]) / 2.0;
            }else return nums1[s1/2] + 0.0;
        }
        if((s1+s2)==2) return (nums1[0] + nums2[0]) / 2.0;
        int cut1=(s1%2==0?(s1/2):(s1/2+1));
        int cut2=(s2%2==0?(s2/2):(s2/2+1));
        if(s1%2==1&&s2%2==1) s1>s2?cut1--:cut2--;
        bool first=true, change=false;
        while(true){
            change=false;
            if((cut1==0||cut2==0||cut1==s1||cut2==s2)&&first==false) return cal_ans(nums1, nums2, cut1, cut2);
            if(cut1<s1){
                if(nums2[cut2-1]>nums1[cut1]){
                    cut2--;
                    cut1++;
                    first=false;
                    change=true;
                }
            }
            if(cut2<s2){
                if(nums1[cut1-1]>nums2[cut2]){
                    cut2++;
                    cut1--;
                    first=false;
                    change=true;
                }
            }
            if(change==false) return cal_ans(nums1, nums2, cut1, cut2);
        }
        return 0.0;
    }
};
```