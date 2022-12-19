### 解题思路
滑动窗口解法。

### 代码

```c
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b


int isValidWindow(int * win, int left , int right, int k)
{
  int sum0  =0;
  for(int i = left; i<= right; i++)
  {
    if(win[i]==0)
    {
      sum0++;
    }

  }
  if(sum0>k)
  {
    return 0;
  }
  return 1;
}

int longestOnes(int* A, int ASize, int k){

int windows[ASize+1];
for(int i = 0; i < ASize+1; i++)
{
  windows[i] = -1;
}
int count1 = 0;
int count0 = 0;
int maxvalue = 0;
int left = 0; int right = 0;
while(right < ASize)
{
  windows[right] = A[right];

  if(A[right]==1)
  {
    count1++;
  }
  else {
    count0++;
  }
  right++;  
  if(count0 <=k)
  {
      maxvalue = max(maxvalue,right-left);
  }
  while(count0 > k)
  {
    if(windows[left] == 0)
    {
      count0--;
    }
    else{
      count1--;
    }
    left++;
  }
}
return maxvalue;
}
```