
```
int index = address.indexOf(".");
StringBuilder sb = new StringBuilder(address);
while(index >= 0){
    sb.insert(index+1,"]").insert(index,"[");
    index = sb.indexOf(".",index+2);
}

```
