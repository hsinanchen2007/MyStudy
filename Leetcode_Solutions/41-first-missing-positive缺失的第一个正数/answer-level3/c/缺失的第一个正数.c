暴力破解：若不存在正整数，则结果为1；若存在正整数，则结果<=max+1，暴力max*size遍数组。max为常数，size为n，保证时间为O(N)
int firstMissingPositive(int* nums, int numsSize){
      int i = 0;
      int zero_count=0;
      int max = 0;
      for(i = 0;i < numsSize;i++)
      {
          if (nums[i] > max)
          {
              max = nums[i];
          }
          if (nums[i] <= 0)
          {
              zero_count += 1;
              nums[i] = 0;
          }
      }
      if (max == 0)
      {
          return 1;
      }
      else
      {
          int j = 0;
          for(i = 1;i <= max;i++)
          {
              for(j = 0;j < numsSize;j++)
              {
                  if(nums[j] == i)
                  {
                      break;
                  }
              }
              if(j == numsSize)
              {
                  return i;
              }
          }
          if(i == max + 1)
          {
              return i;
          }
      }
      return 0;
}