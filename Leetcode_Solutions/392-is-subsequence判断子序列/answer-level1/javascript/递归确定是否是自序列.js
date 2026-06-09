### 解题思路
利用递归解决问题，将问题由大问题化解为更小的子问题的方式

### 代码

```javascript
const  isSubsequence = (s, t)=>{
    const helper=(s,t)=>{
        if(s.length<1) return true;
        if(t.length<1) return false;
        let first=t.indexOf(s[0]);
        if(first===-1){
            return false;
        }else{
            return helper(s.slice(1),t.slice(first+1));
        }
    };
    return helper(s,t);
};
```