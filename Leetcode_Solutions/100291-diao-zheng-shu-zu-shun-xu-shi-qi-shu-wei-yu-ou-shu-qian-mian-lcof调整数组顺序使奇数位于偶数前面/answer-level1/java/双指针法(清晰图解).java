### 解题思路
1. 设计两个指针i和j,分别为0和nums.length-1;
2. 执行循环直到j-i<1;
3. 如果第一个指针为奇数，第二个指针为偶数，i++,j--;
4. 如果第一个指针为奇数，第二个指针为奇数，i++;
5. 如果第一个指针为偶数，第二个指针为偶数，j--;
6. 其余情况下，交换两个指针数。








<![幻灯片20.PNG](https://pic.leetcode-cn.com/342e3da21bc12546e31f26a00160dc71bb437549f32578b867f636d088cade7a-%E5%B9%BB%E7%81%AF%E7%89%8720.PNG),![幻灯片21.PNG](https://pic.leetcode-cn.com/15499c31f2ae34fa74afb3c3c93af4115185dd18827de9f0e6ed14cb88acc798-%E5%B9%BB%E7%81%AF%E7%89%8721.PNG),![幻灯片22.PNG](https://pic.leetcode-cn.com/a08b079874c856962e77491a46af1ae0265716c3af33221c0b434d812b44c3a3-%E5%B9%BB%E7%81%AF%E7%89%8722.PNG),![幻灯片23.PNG](https://pic.leetcode-cn.com/6bba8050753a4bbce520ec3f533e3b2bf46d65c27cb0f0bed560745f8fe4cfb4-%E5%B9%BB%E7%81%AF%E7%89%8723.PNG),![幻灯片24.PNG](https://pic.leetcode-cn.com/856bca6ab9c3a480bc6be24d4c8f9ac86e05802b6148df5e009be96c3ad7ce3d-%E5%B9%BB%E7%81%AF%E7%89%8724.PNG),![幻灯片25.PNG](https://pic.leetcode-cn.com/ffad59032dfbc05cc5fc9cd09a23faa9304bae1c1cb2940a19633a4b83868cb1-%E5%B9%BB%E7%81%AF%E7%89%8725.PNG),![幻灯片26.PNG](https://pic.leetcode-cn.com/d744ac64db6cdf4b998c304d8d3c4594a59348bf8206d74526719c8a9f7d36dc-%E5%B9%BB%E7%81%AF%E7%89%8726.PNG)>

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        
		int i=0,j=nums.length-1;
		while(j-i>=1) {
			if((nums[i]&1)==1 && (nums[j]&1)==0) {
				i++;
				j--;
			}else if((nums[i]&1)==1 && (nums[j]&1)==1){
				i++;
			}else if((nums[i]&1)==0 && (nums[j]&1)==0) {
				j--;
			}else {
				int temp=nums[i];
				nums[i]=nums[j];
				nums[j]=temp;
				i++;
				j--;
			}
		}
		return nums;
    }
}
```