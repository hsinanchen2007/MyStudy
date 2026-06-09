//--------PeanutLiu----------//
int multiply(int A, int B){
    if (B == 0)  return 0;
    return A + multiply(A, B - 1);
}
