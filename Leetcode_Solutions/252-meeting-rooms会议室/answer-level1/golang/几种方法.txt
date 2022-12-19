# 方法一

![image.png](https://pic.leetcode-cn.com/d78d289b7aa35a5f76bbce7193cf1435d1066a6eee451707aea1aca6f7d89592-image.png)
将每个时刻是否有空都标注出来判断.
# 方法二

![image.png](https://pic.leetcode-cn.com/ce11722eb6a143c027920d49686979c9988c4fdc8e7436772f5139edf6f815e8-image.png)
两两之间比较,判断是否有交集.
# 方法三

![image.png](https://pic.leetcode-cn.com/96463c98972acf30e5c2d860c1bea46018ff74bc7bbd6eb06fdd832435362eb7-image.png)
使用排序方法,将start排序, 只要end不交集,即为安全;
# 方法四

![image.png](https://pic.leetcode-cn.com/0f8a93f48aad89ccf4c0c9ffac2763a0c3e624473c3d32fb45cf2e7e554ace7c-image.png)
由于排序map比较重,这里修改为排序key.耗时明显降低