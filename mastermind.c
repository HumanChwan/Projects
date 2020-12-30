#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void intToArray(int numToConvert, int numOfDigits, int arr[]); 
void arraySort(int arr[], int length);
int checkRepeat(int num, int numofdig, int maxValue, int minValue, int numToGuessArr[]);

int main()
{
  //Declaring variables
  int correctDigit, correctPlace, guess, attempts = 5;
  int numToGuess, win = 0, numOfDigits = 3, maxValue = 1, minValue;
  int guessArr[numOfDigits], numToGuessArr[numOfDigits];

  //For repeated digits check
  int repeat = 0;
  char userInpRepeat = '2';

  //Setting number of digits in number
  do
  {
    printf("How many digits should the random number have? (3-9)\n");
    scanf("%d", &numOfDigits);
  } while (!(numOfDigits <= 9 && numOfDigits >= 3));

  //Setting the max and min value of the random number
  for (int i = 0; i < numOfDigits; i++)
  {
    maxValue *= 10;
  }
  minValue = maxValue / 10;
  maxValue--;
  // printf("min is %d and max is %d\n", minValue, maxValue); // checking min and max

  //Setting whether digits can repeat
  while (!(userInpRepeat == 'y' || userInpRepeat == 'n'))
  {
    printf("Can the number have repeated digits?(y/n)\n");
    fflush(stdin);
    scanf("%c", &userInpRepeat);
    // printf("%c", userInpRepeat); // Checking userInpRepeat
  }

  //Setting random number
  srand(time(0));

  if (userInpRepeat = 'n')
  {
    repeat = 0;
    do
    {
      numToGuess = (rand() % (maxValue - minValue + 1)) + minValue;
    } while (checkRepeat(numToGuess, numOfDigits, minValue, minValue, numToGuessArr) != 0);
  }
  else
  {
    repeat = 1;
    numToGuess = (rand() % (maxValue - minValue + 1)) + minValue;
  }

  // printf("%d\n", numToGuess); // Checking number
  if (userInpRepeat == 'y')
  {
    printf("A random number with %d digits with or without repeated digits has been chosen\n", numOfDigits);
  }
  else if (userInpRepeat == 'n')
  {
    printf("A random number with %d digits without repeated digits has been chosen\n", numOfDigits);
  }
  //else is not requirement. kekek.
  else
  {
    printf("Input should be 'y' or 'n'");
  }

  //Setting number of attempts
  printf("How many attempts would you like to guess the number?\n");
  scanf("%d", &attempts);
  printf("You have %d attempts to guess the random number\n", attempts);

  //Taking input of guesses
  for (int i = 0; i < attempts; i++)
  {
    int correctDigit = 0;
    int correctPlace = 0;
    do
    {
      printf("Enter guess %d: \n", (i+1));
      scanf("%d", &guess);
    } while(!(guess>minValue && guess<maxValue && checkRepeat(guess, numOfDigits, maxValue, minValue, guessArr) == repeat));
    //guess can be equal to max and min right?

    //Converting guess and numtoguess to array for comparison of digits

    intToArray(numToGuess, numOfDigits, numToGuessArr);
    intToArray(guess, numOfDigits, guessArr);

    //Checking guess
    for (int j = 0; j < numOfDigits; j++)
    {
      if (numToGuessArr[j] == guessArr[j])
      {
        correctPlace += 1;
      }
      for (int k = 0; k < numOfDigits; k++)
      {
        if (numToGuessArr[k] == guessArr[j])
        {
          correctDigit += 1;
        }
      }
    }
    //Check for win
    int j = i + 1;
    if (correctPlace == numOfDigits)
    {
      printf("You have guessed the number correctly in %d attempts\n", j);
      win = 1;
      break;
    }
    //Print hints after guess
    printf("Guess %d:           \n", j);
    printf("Correct Digits:   %d\n", correctDigit);
    printf("Correct Position: %d\n", correctPlace);
  }
  //If guess wasn't correct for number of attempts
  if (win == 0)
  {
    printf("You couldn't guess the number in %d tries\n", attempts);
    printf("The number was %d\n", numToGuess);
  }

  fflush(stdin);
  getchar();
  
  return 0;
}

// Function to convert integer into array of its digits
void intToArray(int numToConvert, int numOfDigits, int arr[])
{
  int temp = numToConvert;
  for (int i = 0; i < numOfDigits; i++)
  {
    arr[i] = temp % 10;
    temp /= 10;
  }
}

//Function to sort array
void arraySort(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < length; j++)
    {
      int temp;
      if (arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
<<<<<<< HEAD

//Function to check number for repeated digits
=======
//Bois why is "maxValue", "minValue" & "numToGuessArr" passed? you are not even using them
>>>>>>> 8c129cecb52869deb4cce589fd2271e34fe3ae97
int checkRepeat(int num, int numOfDigits, int maxValue, int minValue, int numToGuessArr[]){
      int repeat = 0;
      int tempNumToGuessArr[numOfDigits];
      intToArray(num, numOfDigits, tempNumToGuessArr);
      arraySort(tempNumToGuessArr, numOfDigits);
      for (int i = 0; i < numOfDigits - 1; i++)
      {
        if (!(tempNumToGuessArr[i + 1] < tempNumToGuessArr[i]))
        {
          repeat++;
          break;
        }
      }
      return repeat;
}


//Yaar yeh toh tune good boi wala kaam kardiya waise... :thumbs_up: