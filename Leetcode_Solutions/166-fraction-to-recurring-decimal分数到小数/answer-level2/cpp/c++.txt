### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        long long nums1=numerator;
        long long nums2=denominator;
        int tag=1;
        if((nums1<0 && nums2>0) || (nums1>0 && nums2<0)){
            tag=-1;
            if(nums1<0) nums1=abs(nums1);
            if(nums2<0) nums2=abs(nums2);
        } 
        long long a=nums1/nums2;
        res+=to_string(a);
        if(tag==-1) res="-"+res;
        long long mod = nums1%nums2;
        if(mod==0) return res;
        res+=".";

        unordered_set<int> residue;
        residue.insert(mod);
        nums1 = mod*10;
        string cur;
        int flag=0;
        while(residue.find(nums1%nums2)==residue.end()){
            cur+=to_string(nums1/nums2);
            if(nums1%nums2!=0) {
                residue.insert(nums1%nums2);
                nums1 = nums1%nums2*10;
            }
            else {
                flag=1;
                break;      
            }    
        }

        if(flag){
            res+=cur;
            return res;
        }

        long long modcir = nums1%nums2;
        string p;
        while(mod!=modcir){
            p+=to_string(mod*10/nums2);
            mod=mod*10%nums2;            
        }
        res+=p;
        res+="(";
        res+=to_string(mod*10/nums2);
        mod=mod*10%nums2;
        string q;
        while(mod!=modcir){
            q+=to_string(mod*10/nums2);
            mod=mod*10%nums2;
        }
        res+=q;
        res+=")";
        return res;
    }
};
```