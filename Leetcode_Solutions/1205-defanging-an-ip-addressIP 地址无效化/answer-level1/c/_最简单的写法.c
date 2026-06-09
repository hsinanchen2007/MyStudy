```
char * defangIPaddr(char * address){
    char * res = (char *) malloc(50 * sizeof(char));
    memset(res, 0, 50 * sizeof(char));
    int p1, p2, p3, p4;
    sscanf(address, "%d.%d.%d.%d", &p1, &p2, &p3, &p4);
    sprintf(res,"%d[.]%d[.]%d[.]%d", p1, p2, p3, p4);
    return res;
}
```
