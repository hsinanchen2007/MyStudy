先统计出现次数，每次找出次数最多的
class Solution {
public:
    
int max(int arr[],int n)
{
    int index = 0;
    int i;
    int max = arr[0];
    for(i = 0;i < n; i++)
    {
      if(arr[i] > max)
      {
          max = arr[i];
          index = i;
      }
    }
    return index;
}
    string frequencySort(string s) {
        int x[128]={0};
        for(int i=0;i<s.size();i++)
        {
            x[s[i]-' ']++;
        }
       
        int j=0;
        while(1)
        {
            int i=max(x,128);
            if(x[i]==0)
                break;
           while(x[i]>0)
           {
            s[j]=' '+i;
            j++;
            x[i]--;  
         }
            x[i]=0;
        }
        return s;
    }
};