```
return [z for t in zip([x for x in A if x%2==0],[y for y in A if y%2!=0]) for z in t]
```
