### 解题思路
按层次保存N叉数的值和子树个数即可

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

class Codec {
  	constructor() {
        
    }
  
    /** 
     * @param {Node} root
     * @return {string}
     */
    // Encodes a tree to a single string.
    serialize = function(root) {
        let queue = [root], res = [], temp, child;
        while(queue.length){
            temp = queue.shift();
            if(temp){
                child = temp.children.length;
                for(let i = 0; i < child; i++){
                    queue.push(temp.children[i]);
                }
                res.push([temp.val,child]);
            }
        }
        return JSON.stringify(res);
        //[[1,3],[3,2],[2,0],[4,0],[5,0],[6,0]]
    };

    /** 
     * @param {string} data 
     * @return {Node}
     */
    // Decodes your encoded data to tree.
    deserialize = function(data) {
        let queue = JSON.parse(data);
        if(queue.length == 0) return null;
        let [node,child] = queue.shift(),
            root = new Node(node,[]),
            cur = [[root, child]],temp,level,len,index;
        while(queue.length){
            //cur:当前节点和子节点个数，level:下一层子节点，child:下一层子节点个数 按子节点个数取数组
            len = cur.length;
            level = queue.splice(0,child);
            child = 0, index = 0;
            for(let i = 0; i < len; i++){
                for(let j = 0; j < cur[i][1]; j++){
                    temp = new Node(level[index][0],[]);
                    child += level[index][1];
                    cur[i][0].children[j] = temp;
                    cur.push([temp,level[index][1]]);
                    index++;
                }
            }
            cur.splice(0,len);
        }
        return root;
    };

}
// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```