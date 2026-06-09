```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(i+k>=nums.size()){
                a[i+k-nums.size()]=nums[i];
            }
            else{
                a[i]=nums[i];
            }
        }
        
    }
};
```

第二个超时了。。。
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp;
        int s=nums.size();
        for(int i=0;i<k;i++){
            temp=nums[s-1];
            for(int j=s-2;j>=0;j--){
                nums[j+1]=nums[j];
            }
            nums[0]=temp;
        }
        
    }
};
```



抄的
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int count=0;
        int temp;
        for(int i=0;count<nums.size();i++){
            int current= i;
            int pre=nums[i];
            do{
                int next=(current+k)%nums.size();
                temp=nums[next];
                nums[next]=pre;
                pre=temp;
                current=next;
                count++;
            }while(current!=i);
        }

    }
};
```


