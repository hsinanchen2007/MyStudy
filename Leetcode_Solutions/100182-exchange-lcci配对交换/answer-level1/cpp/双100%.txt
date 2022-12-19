```
class Solution {
public:
    int exchangeBits(int num) {
        vector<int> arr;
        while(num)
        {
            arr.push_back(num%2);
            num/=2;
        }
        if(arr.size()%2!=0)
            arr.push_back(0);
        for(int i=0;i<arr.size();i+=2)
        {
            swap(arr[i],arr[i+1]);
            /*int tmp;
            tmp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tmp;*/
        }
        int sum=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            sum=sum*2+arr[i];//注意这里，以后位运算可以不用求fig了
        }
        return sum;
    }
};
```
