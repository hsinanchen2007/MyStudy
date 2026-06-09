char * defangIPaddr(char * address){
    int a, b, c, d;
    char *str = malloc((strlen(address) + 10) * sizeof(char)); 
    sscanf(address, "%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(str, "%d[.]%d[.]%d[.]%d" , a, b, c, d);
    return str;
}