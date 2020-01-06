//This is a C++ implementation of the Rabin Klark Algorithm

#include <bits/stdc++.h> 
using namespace std; 
  
#define d 256 //d is the # of characters in the input
  
/*
  pat -> pattern
  txt -> text
  q -> A prime number  
*/

void search(char pattern[], char text[], int q)  
{  
  int M = strlen(pattern);
  int N = strlen(text);
  int i, j;
  int p = 0; //hash value pattern
  int t = 0; //hash value text
  int h = 1; //value of h would be "pow(d, M-1)%q"
  
  for (i = 0; i < M - 1; i++)
    h = (h * d) % q; //calculates the hash value of pattern and the first window of text
  
  for (i = 0; i < M; i++)
  {
    p = (d * p + patter [i]) % q;
    t = (d * t + text [i]) % q;
  }
  
  for (i = 0; i <= N - M; i++) //shifts the pattern over text individually
  {
    
  //checks the hash values of current window of text & pattern. If values match then only check for characters individually
  if ( p == t )
  {
    for (j = 0; j < M; j++) //individual pattern check
    
    {
      if (txt[i+j] != pat[j])
        break;
    }
    
    if (j == M) // if p == t and pattern [0...M-1] = text[i, i+1, ...i+M-1]
      cout<<"Pattern found at index "<< i<<endl;
  }
    
    //calculates the hash value for the next window of text & removes the leading digit & adds a trailing digit
    if ( i < N-M )
    {
      t = (d*(t - text[i]*h) + text[i+M])%q; //made a mistake by producing a negative t value converting it to positive
      if (t < 0)
        t = (t + q);
    }
  }
}

//test drive
int main()
{
  char text[] = "Everything is awesome";
  char pattern[] = "awesome";
  
  int q = 101; //prime #
  search (pattern, text, q);
    return 0;  
}
