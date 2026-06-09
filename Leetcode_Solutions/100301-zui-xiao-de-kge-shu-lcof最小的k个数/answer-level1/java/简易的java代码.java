### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr,int k){
		int[] res = new int[k];
		Arrays.sort(arr);
		for(int i=0;i<k;i++){
			res[i] = arr[i];
		}
		return res;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/2d4c1d0e210222597d7c82b4db1acc55d1160f40183d115001a7756dda5b0711-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/527d93582a5de914c86939eb4cdc45def24deecc67b3a4abeb14dd3d8bd0f1cc-wechat.png)

