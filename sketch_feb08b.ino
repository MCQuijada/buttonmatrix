const int F = 3;
const int C = 3;

int filas[] = {5,6,7};
int columnas[] = {2,3,4};

int matriz[F][C];

void setup() {
  for (int i = 0; i < F; i++){
    pinMode(filas[i],INPUT);
  }
  for (int i = 0; i < C; i++){
    pinMode(columnas[i],INPUT);
  }
  Serial.begin(9600);
}

void leerMatriz(){
  for (int i = 0; i < F; i++){
    pinMode(filas[i],OUTPUT);
    digitalWrite(filas[i],LOW);
    for (int j = 0; j < C; j++){
      pinMode(columnas[j],INPUT_PULLUP);
      matriz[i][j] = digitalRead(columnas[j]);
      pinMode(columnas[j],INPUT);
    }
    pinMode(filas[i],INPUT);
  }
}

void loop() {
  leerMatriz();
  Serial.println();
  for (int i = 0; i < F; i++){
    for (int j = 0; j < C; j++){
      Serial.print(matriz[i][j]);  
    }
    Serial.println(" ");
  }
  delay(100);
}
