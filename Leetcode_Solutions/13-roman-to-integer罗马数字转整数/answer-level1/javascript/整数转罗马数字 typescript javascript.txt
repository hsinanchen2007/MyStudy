思路：当某数小于右侧的字符值时，相当于加上该数的相反数
1.使用js实现
```

const map = new Map();
map.set('I', 1);
map.set('V', 5);
map.set('X', 10);
map.set('L', 50);
map.set('C', 100);
map.set('D', 500);
map.set('M', 1000);

const romanToInt = function(s) {
  let result = 0;
  for (let i = 0; i < s.length; i++) {
    if (map.get(s[i]) < map.get(s[i + 1])) {
      result = result - map.get(s[i]);
    } else {
      result = result + map.get(s[i]);
    }
  }
  return result;
};


```
2.使用ts
```

enum Rome{
    I=1,
    V=5,
    X=10,L=50,C=100,D=500,M=1000

}
const romeToInt = function (s:string) {
    let result:number=0;
    for(let i=0;i<s.length;i++){
        if(Rome[s[i]]<Rome[s[i+1]]){
            console.log(Rome[s[i]]);
            result=result-Rome[s[i]]
        }else{
            console.log(Rome[s[i]]);
            result=result+Rome[s[i]]
        }
    }
    return result
};

```