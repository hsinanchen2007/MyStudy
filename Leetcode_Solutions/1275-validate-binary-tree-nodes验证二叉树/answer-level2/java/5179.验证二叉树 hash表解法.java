

如果某个元素在两边共出现了两次说明存在同一指向

或者有指向0的子树

或者某个元素没有出现在两边则说明不连通

于是 遍历左右放入hashSet中，如果重复则返回false

接着判断0是否在其中

最后判断是否所有元素都放入

```
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
    	HashSet<Integer> hashSet = new HashSet<>();
    	int len1 = leftChild.length;
    	int len2 = rightChild.length;
    	if(len1!=len2) {
    		return false;
    	}
    	for(int i = 0;i<len1;i++) {//没有重复
    		if(leftChild[i]!=-1) {//左边进去
    			if(hashSet.contains(leftChild[i])) {//如果包含返回false
    				return false;
    			}else {//否则加入到hash表中
					hashSet.add(leftChild[i]);
				}
    		}
    		if(rightChild[i]!=-1) {//右边同理
    			if(hashSet.contains(rightChild[i])) {
    				return false;
    			}else {
					hashSet.add(rightChild[i]);
				}
    		}
    	}
    	if(hashSet.contains(0)) {//判断是否有指向0的
    		return false;
    	}
    	for(int i = 1;i<len1;i++) {
    		if(!hashSet.contains(i)) {//某一个不在hash中说明有断的地方
    			return false;
    		}
    	}
    	return true;
    	
    }
}
```
