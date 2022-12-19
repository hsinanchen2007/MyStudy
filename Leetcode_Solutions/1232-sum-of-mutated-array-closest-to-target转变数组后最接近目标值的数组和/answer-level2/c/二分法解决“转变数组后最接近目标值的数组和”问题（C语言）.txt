### 解题思路
典型二分法题型，题目难点在于结果的确认。

1.首先确定上下限分别为1和max(arr)

2.然后二分选择不同的中值，会产生大于等于或小于target的结果。

3.如果大于等于，则说明中值选大了，需要减小；否则需要增加。

4.题目难点在于结果的确认，二分产生的结果是大于等于target的值ll，而ll-1是否差值更小，需要重新计算确认。

5.最终重新计算确认ll或者ll-1哪个差值更小，为最终结果。

![image.png](https://pic.leetcode-cn.com/225805749f28a75636bf4163aebab8bee577d627c3dd3b0322b01056f13f28f5-image.png)


### 代码

```c
#define MMIN(a, b)          ((a) < (b)? (a) : (b))
#define MMAX(a, b)          ((a) > (b)? (a) : (b))

//【算法思路】二分。二分上限为数组最大值，注意结果确认ll和ll-1哪个符合要求
int findBestValue(int* arr, int arrSize, int target){
    if(arrSize == 1)
    {
        return MMIN(arr[0], target);
    }

    //找到数组中的最大值
    int max = INT_MIN;
    for(int i = 0; i < arrSize; i++)
    {
        max = MMAX(max, arr[i]);
    }

    int ll = 1, rr = max;

    while(ll < rr)
    {
        //表明小于target，取值偏小
        bool flag = true;

        int mid = (ll + rr) / 2;

        int sum = 0;
        for(int i = 0; i < arrSize; i++)
        {
            sum += (arr[i] > mid)? mid : arr[i];

            if(sum > target)
            {
                //已经大于target
                flag = false;
                break;
            }
        }

        if(flag == false)
        {
            rr = mid;
        }
        else
        {
            ll = mid + 1;
        }
    }

    //printf("ll = %d\n", ll);

    //重算一下ll和ll-1，确认结果
    int ll0 = ll - 1;
    int ll1 = ll;
    int sum0 = 0, sum1 = 0;

    for(int i = 0; i < arrSize; i++)
    {
        sum0 += (arr[i] > ll0)? ll0 : arr[i];
        sum1 += (arr[i] > ll1)? ll1 : arr[i];
    }

    //printf("sum0 = %d, sum1 = %d", sum0, sum1);

    if(abs(target - sum0) <= abs(target - sum1))
    {
        return ll0;
    }
    else
    {
        return ll1;
    }
}
```