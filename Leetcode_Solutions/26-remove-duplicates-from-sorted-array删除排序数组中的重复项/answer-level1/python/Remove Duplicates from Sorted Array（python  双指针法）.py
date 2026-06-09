i为慢指针，j为快指针。

当nums[i] = nums[j]时，跳过不做记录。由于数组已排好序，不必考虑之前或以后出现相同元素。

当nums[i] != nums[j]时,i = i+1记录。
![lALPDgQ9q4Kp2AfNAZPNAsU_709_403.png](https://pic.leetcode-cn.com/198733ff134f6defc15f2537d6af6ca283c291974db15260daed25ad49db34ed-lALPDgQ9q4Kp2AfNAZPNAsU_709_403.png)
