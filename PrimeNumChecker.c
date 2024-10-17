#include<stdio.h>
#include<math.h>

void PrimeChecker(long long int n){
  if(n < 2){
    printf("Error");
  }
  for(long long int i = 2; i < n; i++){
    long long int fermat = pow(i,(n-1))-1;
    if(fermat % n == 0){
      printf("True");
      break;
    } else{
      printf("False");
      break;
    }
  }
}

int main(){
  long long int n;
  scanf("%lld", &n);
  PrimeChecker(n);
  return 0;
}