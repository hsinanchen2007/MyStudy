双指针法：设置两个下标，分别指向nums1和nums2，比较nums1[cur1]和nums2[cur2],谁小谁的下标+1，直到总共走(sizeSum-1)/2步找到中位数，再分情况讨论sizeSum为奇偶数即可。
时间复杂度O(log(m+n));
```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        double a=0.0;
        if(nums1.size()==0 &&nums2.size()==0)
        return a;
        //nums1为空
        if(nums1.size()==0)
        {
            if(nums2.size()%2==0){
                a=(double)(nums2[(nums2.size()-1)/2]+nums2[(nums2.size()-1)/2+1])/2;
            }
            else
                a=(double)nums2[(nums2.size()-1)/2];
        }
        //nums2为空
        else if(nums2.size()==0)
        {
            if(nums1.size()%2==0){
                a=(double)(nums1[(nums1.size()-1)/2]+nums1[(nums1.size()-1)/2+1])/2;
            }
            else
                a=(double)nums1[(nums1.size()-1)/2];
        }
        //两个都不为空
        else{
            int cur1=0,cur2=0;//nums1、nums2下标指针
            int sizeSum=nums1.size()+nums2.size();//两个数组总共的长度
            bool flag=0;//标记退出循环时中位数在nums1还是nums2
            int f=0;//标记是否有数组刚好遍历完，为1 nums1遍历完
            int i;
            //数组总长度为偶数

            if(sizeSum%2==0){
                //主循环
                for(i=0;i<=(sizeSum-1)/2;++i){
                    if(nums1[cur1]<=nums2[cur2])
                    {
                        flag=0;
                        cur1++;
                    }
                    else{
                        flag=1;
                        cur2++;
                    }
                    if(cur1>=nums1.size()){
                        f=1;
                        break;
                    }
                    if(cur2>=nums2.size()){
                        f=2;
                        break;
                    }
                        
                }
                //循环完成，两个数组都没有遍历完
                if(f==0){
                    //左中位数在数组nums2
                    if(flag){
                            int tmp=nums2[cur2-1];
                            int tmp2=min(nums1[cur1],nums2[cur2]);
                            a=(double)(tmp+tmp2)/2;
                    }
                    else{
                        int tmp=nums1[cur1-1];
                        int tmp2=min(nums1[cur1],nums2[cur2]);
                        a=(double)(tmp+tmp2)/2;
                    }
                    
                }
                //数组nums1遍历完
                else if(f==1){
                    //如果刚好找到左中位数
                    if(i==(sizeSum-1)/2){
                        int tmp=nums2[cur2];
                        a=(double)(tmp+nums1[cur1-1])/2;
                    }
                    else{
                        for(int j=i+1;j<=(sizeSum-1)/2;++j){
                            cur2++;
                        }
                        a=(double)(nums2[cur2-1]+nums2[cur2])/2;
                    }
                }
                //f=2
                else{
                    if(i==(sizeSum-1)/2){
                        int tmp=nums1[cur1];
                        a=(double)(tmp+nums2[cur2-1])/2;
                    }
                    else{
                        for(int j=i+1;j<=(sizeSum-1)/2;++j){
                            cur1++;
                        }
                        a=(double)(nums1[cur1-1]+nums1[cur1])/2;
                    }
                
                }
            }
            //sizeSUM==奇数
             else{
                    for(i=0;i<=(sizeSum-1)/2;++i){
                    if(nums1[cur1]<=nums2[cur2])
                    {
                        flag=0;
                        cur1++;
                    }
                    else{
                        flag=1;
                        cur2++;
                    }
                    if(cur1>=nums1.size()){
                        f=1;
                        break;
                    }
                    if(cur2>=nums2.size()){
                        f=2;
                        break;
                    }
                    }
                    if(f==0){
                        if(flag==0){
                            a=(double)nums1[cur1-1];
                        }
                        else{
                            a=(double)nums2[cur2-1];
                        }
                    }
                    else if(f==1){
                        if(i==(sizeSum-1)/2){
                            a=(double)nums1[cur1-1];
                        }else{
                            for(int j=i+1;j<=(sizeSum-1)/2;++j){
                                cur2++;
                                a=(double)nums2[cur2-1];
                            }
                        }
                    }
                    else{
                        if(i==(sizeSum-1)/2){
                            a=nums2[cur2-1];
                        }else{
                            for(int j=i+1;j<=(sizeSum-1)/2;++j){
                                cur1++;
                                a=nums1[cur1-1];
                            }
                        }

                    }
            
            }
        
        }
        return a;
    };
```

