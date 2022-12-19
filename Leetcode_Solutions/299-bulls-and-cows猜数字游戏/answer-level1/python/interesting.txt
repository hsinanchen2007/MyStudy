生命短且艰，我选Python舔
```

cnt=0
for i in range(len(secret)):
        if secret[i]==guess[i]:
        cnt+=1
return str(cnt)+"A"+str(sum((collections.Counter(secret)&collections.Counter(guess)).values())-cnt)+"B"
```

```




