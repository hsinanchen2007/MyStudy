分别从数组1、2中取0-k个最大的数 dp[i]=dp[i+1].RemoveFirstLeftMinRight() {7,5,6,3},移除5得到 {7,6,3}
比较max((0,k)、(1,k-1)...(k,0))哪个最大
C#,JavaScript(C#翻译的),目前表现还可以

C# 
```
public class Solution {
    //get 0 from a ,get k from b
    //get 1 from a ,get k-1 from b
    //get 2 from a ,get k-2 from b
    public int[] MaxNumber(int[] nums1, int[] nums2, int k)
    {
        if (nums1.Length > nums2.Length)
        {
            return MaxNumber(nums2, nums1, k);
        }

        var array = new int[k];

        for (var i = 0; i < array.Length; i++)
        {
            array[i] = int.MinValue;
        }

        if (nums1.Length + nums2.Length == k)
        {
            return MergeCompare(nums1, nums2, array);
        }

        var k1 = GetMaxMToK(nums1, k, k > nums2.Length ? k - nums2.Length : 0);
        var k2 = GetMaxMToK(nums2, k, k > nums1.Length ? k - nums1.Length : 0);

        for (var i =0 ; i < k2.Length; i++)
        {
            if (k - i >= k1.Length)
            {
                if (i == k)
                {
                    array = MergeCompare(k1[0], k2[i], array);
                }
            }
            else
            {
                array = MergeCompare(k1[k - i], k2[i], array);
            }
        }

        return array;
    }

    //m,m+1,m+2...k个最大的数字
    //
    //0 :null
    //1 :null
    //...
    //m :[num_1,num_2,....num_m]
    //...
    //k :[num_1,num_2,....num_k]
    public int[][] GetMaxMToK(int[] nums, int k, int m)
    {
        if (k == 0)
        {
            return new int[0][];
        }

        if (k > nums.Length)
        {
            k = nums.Length;
        }

        var dp = new int[k + 1][];

        for (var i = k; i >= m; i--)
        {
            if (i == k)
            {
                dp[i] = GetMaxK(nums, i);
            }
            else
            {
                dp[i] = GetMaxK(dp[i + 1], i);
            }
        }

        return dp;
    }

    //最大k个数
    public int[] GetMaxK(int[] nums, int k)
    {
        if (k == 0)
        {
            return new int[0];
        }

        var size = Math.Min(nums.Length, k) + 1;
        var dp = new int[k];

        //先填满
        for (int i = nums.Length - 1, m = size - 1; i >= 0 && m >= 1; i--, m--)
        {
            dp[m - 1] = nums[i];
        }

        for (var j = nums.Length - dp.Length - 1; j >= 0; j--)
        {
            if (nums[j] < dp[0])
            {
                continue;
            }

            var start = 0;
            var min = dp[0];

            //干掉第一个比右边小的值
            //如 nums[j]=8  dp={7,5,6,3},移除5得到 dp={8,7,6,3}
            for (var i = 1; i < dp.Length; i++)
            {
                if (min < dp[i])
                {
                    break;
                }

                start = i;
                min = dp[i];
            }

            //for (var i = start; i >= 1; i--)
            //{
            //    dp[i] = dp[i - 1];
            //}
            Array.Copy(dp, 0, dp, 1, start);
            dp[0] = nums[j];
        }

        return dp;
    }

    //拼接并比较 reutrn new>old?new:old;
    public int[] MergeCompare(int[] nums1, int[] nums2, int[] array)
    {
        var i = 0;
        var j = 0;
        var isBigger = false;
        var newArray = new int[array.Length];

        while (i + j < array.Length)
        {
            var index = i + j;

            if (i >= nums1.Length)
            {
                newArray[index] = nums2[j++];
            }
            else if (j >= nums2.Length)
            {
                newArray[index] = nums1[i++];
            }
            else if (nums1[i] > nums2[j])
            {
                newArray[index] = nums1[i++];
            }
            else if (nums1[i] == nums2[j])
            {
                if (IsNums1Bigger(nums1, nums2, i + 1, j + 1))
                {
                    newArray[index] = nums1[i++];
                }
                else
                {
                    newArray[index] = nums2[j++];
                }
            }
            else
            {
                newArray[index] = nums2[j++];
            }

            if (!isBigger)
            {
                if (newArray[index] < array[index])
                {
                    return array;
                }
                else if (newArray[index] > array[index])
                {
                    isBigger = true;
                }
            }
        }

        return newArray;
    }

    //return nums1>nums2
    public bool IsNums1Bigger(int[] nums1, int[] nums2, int i, int j)
    {
        while (i < nums1.Length && j < nums2.Length)
        {
            if (nums1[i] > nums2[j])
            {
                return true;
            }

            if (nums1[i] < nums2[j])
            {
                return false;
            }

            i++;
            j++;
        }

        return nums1.Length - i - (nums2.Length - j) > 0;
    }
}
```

JavaScript(根据C#翻译的)
```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[]}
 */
var maxNumber = function (nums1, nums2, k) {
    if (nums1.length > nums2.length) {
        return maxNumber(nums2, nums1, k);
    }

    var array = new Array(k);

    for (var i = 0; i < array.length; i++) {
        array[i] = -1;
    }

    if (nums1.length + nums2.length == k) {
        return mergeCompare(nums1, nums2, array);
    }

    var k1 = getMaxMToK(nums1, k, k > nums2.length ? k - nums2.length : 0);
    var k2 = getMaxMToK(nums2, k, k > nums1.length ? k - nums1.length : 0);

    for (var i = 0; i < k2.length; i++) {
        if (k - i >= k1.length) {
            //k2更长,可能k1取0个,k2取k个
            if (i == k) {
                array = mergeCompare(k1[0], k2[i], array);
            }
        }
        else {
            array = mergeCompare(k1[k - i], k2[i], array);
        }
    }

    return array;
};

//m,m+1,m+2...k个最大的数字,实际返回k个数组,MaxNumber方法中好处理一点
//
//0 :null
//1 :null
//...
//m :[num_1,num_2,....num_m]
//...
//k :[num_1,num_2,....num_k]
var getMaxMToK = function (nums, k, m) {
    if (k == 0) {
        return [];
    }

    if (k > nums.length) {
        k = nums.length;
    }

    //dp[i]=dp[i+1].removeFirstLeftMinRight();
    var dp = new Array(k + 1);

    for (var i = k; i >= m; i--) {
        if (i == k) {
            dp[i] = getMaxK(nums, i);
        }
        else {
            dp[i] = getMaxK(dp[i + 1], i);
        }
    }

    return dp;
}

var getMaxK = function (nums, k) {
    if (k == 0) {
        return [];
    }

    let size = Math.min(nums.length, k) + 1;
    let dp = new Array(k);

    //先填满
    for (let i = nums.length - 1, m = size - 1; i >= 0 && m >= 1; i-- , m--) {
        dp[m - 1] = nums[i];
    }

    for (let j = nums.length - dp.length - 1; j >= 0; j--) {
        if (nums[j] < dp[0]) {
            continue;
        }

        let start = 0;
        let min = dp[0];

        //干掉第一个比右边小的值
        //如 nums[j]=8  dp={7,5,6,3},移除5得到 dp={8,7,6,3}
        for (let i = 1; i < dp.length; i++) {
            if (min < dp[i]) {
                break;
            }

            start = i;
            min = dp[i];
        }

        for (let i = start; i >= 1; i--) {
            dp[i] = dp[i - 1];
        }

        dp[0] = nums[j];
    }

    return dp;
}

//拼接并比较 reutrn new>old?new:old;
var mergeCompare = function (nums1, nums2, array) {
    var i = 0;
    var j = 0;
    var isBigger = false;
    var newArray = new Array();
    var k = nums1.length + nums2.length;

    while (i + j < k) {
        var index = i + j;

        if (i >= nums1.length) {
            newArray.push(nums2[j++]);
        }
        else if (j >= nums2.length) {
            newArray.push(nums1[i++]);
        }
        else if (nums1[i] > nums2[j]) {
            newArray.push(nums1[i++]);
        }
        else if (nums1[i] == nums2[j]) {
            if (isNums1Bigger(nums1, nums2, i + 1, j + 1)) {
                newArray.push(nums1[i++]);
            }
            else {
                newArray.push(nums2[j++]);
            }
        }
        else {
            newArray.push(nums2[j++]);
        }

        if (!isBigger) {
            if (newArray[index] < array[index]) {
                return array;
            }
            else if (newArray[index] > array[index]) {
                isBigger = true;
            }
        }
    }

    return newArray;
}

//return nums1>nums2
var isNums1Bigger = function (nums1, nums2, i, j) {
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] > nums2[j]) {
            return true;
        }

        if (nums1[i] < nums2[j]) {
            return false;
        }

        i++;
        j++;
    }

    return nums1.length - i - (nums2.length - j) > 0;
}
```
