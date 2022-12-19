**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/8/26
 *
 * 解题思路1：见图
![D7315DAC689C859E52A04FDC6FE8236C.png](https://pic.leetcode-cn.com/f572cef92098e534af6d0144127e3241fabd9792f8a9699b67c2a5ba713cff14-D7315DAC689C859E52A04FDC6FE8236C.png)
 *
 * 解题思路2：移动k个相当于 将数组反转后 在对 0~k-1 和 k~n 进行反转
 */


```
public void rotate1(int[] nums, int k) {

        int length = nums.length;
        int count = 0;
        for(int start = 0; count < length ; start ++){

            int pre = start;
            int next = (pre + k) % length;
            int current = nums[pre];

            do{ // 当前没有拐回来重复
                int temp = nums[next];
                nums[next] = current;
                pre = next;
                next = (pre + k) % length;
                current = temp;
                count ++;
            }while(start != pre);
        }
        int t = 1;
    }

    public void rotate2(int[] nums, int k) {

        reverse(nums,0,nums.length - 1);
        reverse(nums,0,(k-1) % nums.length);
        reverse(nums,k % nums.length,nums.length -1);

        int t = 0;
    }

    /**
     * 反转
     * @param nums
     * @param s
     * @param e
     */
    public void reverse(int[] nums , int s , int e){
        for(int i = s , j = e; i < j; i++ , j--){
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }



    public static void main(String[] args) {
        leetcode189 leetcode189 = new leetcode189();
        leetcode189.rotate2(new int[]{1,2,3,4,5,6},1);
    }
```