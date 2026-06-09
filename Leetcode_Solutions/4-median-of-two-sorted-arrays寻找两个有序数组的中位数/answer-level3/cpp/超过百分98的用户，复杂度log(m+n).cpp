```
class Solution {
private:
    double calcMidNum(int nBegin1,int nBegin2,int nDecrease,vector<int>& nums1, vector<int>& nums2,int nRest, int isOdd,int nSize1,int nSize2){
        //其中一个队列已经移除完了
        if(nBegin1==nSize1){
            if(isOdd){
                return nums2[nBegin2+nRest];
            }
            else{
                return (nums2[nBegin2+nRest]+nums2[nBegin2+nRest+1])/2.0;
            }
        }
        else if(nBegin2==nSize2){
            if(isOdd){
                return nums1[nBegin1+nRest];
            }
            else{
                return (nums1[nBegin1+nRest]+nums1[nBegin1+nRest+1])/2.0;
            }
        }

        if(nDecrease==0){
            if(nRest==1){
                if(nums1[nBegin1]>nums2[nBegin2]){//nums1[nBegin1], nums2[nBegin2]先去掉一个nums2[nBegin2]
                    if(isOdd){
                        return nums1[nBegin1];
                    }
                    else{
                        if(nBegin1==nSize1-1){//nBegin1已经到最后了
                            return (nums1[nBegin1]+nums2[nBegin2+1])/2.0;
                        }
                        else if(nBegin2==nSize2-1){//nBegin2已经到最后了
                            return (nums1[nBegin1]+nums1[nBegin1+1])/2.0;
                        }
                        else{
                            return (nums1[nBegin1]+(nums1[nBegin1+1]<nums2[nBegin2+1]?nums1[nBegin1+1]:nums2[nBegin2+1]))/2.0;
                        }
                    }
                }
                else{
                    if(isOdd){
                        return nums2[nBegin2];
                    }
                    else{
                        if(nBegin1==nSize1-1){//nBegin1已经到最后了
                            return (nums2[nBegin2]+nums2[nBegin2+1])/2.0;
                        }
                        else if(nBegin2==nSize2-1){//nBegin2已经到最后了
                            return (nums2[nBegin2]+nums1[nBegin1+1])/2.0;
                        }
                        else{
                            return (nums2[nBegin2]+(nums1[nBegin1+1]<nums2[nBegin2+1]?nums1[nBegin1+1]:nums2[nBegin2+1]))/2.0;
                        }
                    }
                }
            }
            else{
                if(nums1[nBegin1]>nums2[nBegin2]){//nums1[nBegin1], nums2[nBegin2]取一个，或者取中间值
                    if(isOdd){
                        return nums2[nBegin2];
                    }
                    else{
                        if((nBegin2<nSize2-1) && nums2[nBegin2+1] < nums1[nBegin1]){
                            return (nums2[nBegin2]+ nums2[nBegin2+1] )/2.0;
                        }
                        else{
                            return (nums2[nBegin2]+ nums1[nBegin1] )/2.0;
                        }
                    }
                }
                else{
                    if(isOdd){
                        return nums1[nBegin1];
                    }
                    else{
                        if((nBegin1<nSize1-1) && nums1[nBegin1+1] < nums2[nBegin2]){
                            return (nums1[nBegin1]+ nums1[nBegin1+1])/2.0;
                        }
                        else{
                            return (nums2[nBegin2]+ nums1[nBegin1] )/2.0;
                        }
                    }
                }
            }
        }

        if(nums1[nBegin1+nDecrease-1] > nums2[nBegin2+nDecrease-1]){
            nBegin2 = nBegin2+nDecrease;
            if(nBegin2==nSize2){//一个队列移除完了
                return calcMidNum(nBegin1,nBegin2,0,nums1, nums2,nRest, isOdd,nSize1,nSize2);
            }
        }
        else{
            nBegin1 = nBegin1+nDecrease;
            if(nBegin1==nSize1){//一个队列移除完了
                return calcMidNum(nBegin1,nBegin2,0,nums1, nums2,nRest, isOdd,nSize1,nSize2);
            }
        }

        nDecrease = (nRest+1)/2;
        if(nBegin1+nDecrease<=nSize1 && nBegin2+nDecrease<=nSize2){
            nRest = nRest-nDecrease;
            return calcMidNum(nBegin1, nBegin2,nDecrease, nums1, nums2,nRest,isOdd,nSize1,nSize2);
        }
        else{
            if(nSize1-nBegin1>nSize2-nBegin2){
                nRest = nRest-(nSize2-nBegin2);
                return calcMidNum(nBegin1,nBegin2, nSize2-nBegin2, nums1, nums2,nRest,isOdd,nSize1,nSize2);
            }
            else{
                nRest = nRest-(nSize1-nBegin1);
                return calcMidNum(nBegin1, nBegin2,nSize1-nBegin1, nums1, nums2,nRest,isOdd,nSize1,nSize2);
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nSize1 = nums1.size();
        int nSize2 = nums2.size();
        int totalNum = nSize1+nSize2;
        int isOdd = totalNum%2;
        int midNumPos = (totalNum+1)/2;//中位数的位置，如果偶数个数，则往后再取一个数平均
        int nBegin1 = 0;
        int nBegin2 = 0;
        int nRest =midNumPos-1;//剩下从小到大要移除的个数

        //其中一个队列已经移除完了
        if(nBegin1==nSize1){
            if(isOdd){
                return nums2[nBegin2+nRest];
            }
            else{
                return (nums2[nBegin2+nRest]+nums2[nBegin2+nRest+1])/2.0;
            }
        }
        else if(nBegin2==nSize2){
            if(isOdd){
                return nums1[nBegin1+nRest];
            }
            else{
                return (nums1[nBegin1+nRest]+nums1[nBegin1+nRest+1])/2.0;
            }
        }

        int nDecrease = (nRest+1)/2;
        if(nDecrease<=nSize1 && nDecrease<=nSize2){
            nRest = nRest-nDecrease;
            return calcMidNum(nBegin1, nBegin2,nDecrease, nums1, nums2,nRest,isOdd,nSize1,nSize2);
        }
        else{
            if(nSize1>nSize2){
                nRest = nRest-nSize2;
                return calcMidNum(nBegin1,nBegin2, nSize2, nums1, nums2,nRest,isOdd,nSize1,nSize2);
            }
            else{
                nRest = nRest-nSize1;
                return calcMidNum(nBegin1, nBegin2,nSize1, nums1, nums2,nRest,isOdd,nSize1,nSize2);
            }
        }
    }
};
```
