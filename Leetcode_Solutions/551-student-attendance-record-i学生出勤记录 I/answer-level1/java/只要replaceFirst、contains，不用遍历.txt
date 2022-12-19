```
public boolean checkRecord(String s) {
    boolean ok=false;
    if(!s.replaceFirst("A", "").contains("A") && !s.contains("LLL")) {
        ok=true;
    }
    return ok;
}
```
