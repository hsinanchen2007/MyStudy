## 递归
递归三套,停止条件,递归加处理

```javascript
var reverseKGroup = function(head, k) {
    //1.停止条件,head的next不足k,取消
    let _tmp = head;
    for(i=0;i<k;i++){
        if(!_tmp){
            //保持原有顺序
            return head;
        }
        _tmp = _tmp.next;
    }
    //2.递归, _tmp 的值为4 【k+1】,rnode代表最右侧值
    let rnode = reverseKGroup(_tmp,k);
    //3.翻转处理
    for(let i=0;i<k;i++){
        //此时,head 1 head.next 2，直接将2->1 会失去3的链接,先收集3
        let tmp = head.next;
        head.next = rnode;
        rnode = head;
        head = tmp;
    }
    return  rnode;
};
```