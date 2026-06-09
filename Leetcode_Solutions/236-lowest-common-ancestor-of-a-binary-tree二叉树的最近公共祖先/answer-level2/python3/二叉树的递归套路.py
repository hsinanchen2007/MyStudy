从左右子树要三个信息，分别为：是否存在p，是否存在q，最低公共祖先。
分三种情况：
1、p与q存在于一棵子树中，并且有最低公共祖先
2、p与q分别存在于左右子树中，则最低公共祖先为root
3、剩下的情况：不存在p或q；p或q为root，则最低公共祖先为p或q
![image.png](https://pic.leetcode-cn.com/48fade2d2eac056a9de87ea17f4e9da681d186dae70710bee26b21d19a597d64-image.png)
