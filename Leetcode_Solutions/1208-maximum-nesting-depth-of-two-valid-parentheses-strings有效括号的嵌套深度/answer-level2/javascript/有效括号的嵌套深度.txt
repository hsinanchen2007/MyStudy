```
let maxDepthAfterSplit = (seq,dep=0)=>{
    return seq.split('').map(e=> e==='(' ? dep++ %2 : --dep%2)  
}

```
