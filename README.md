
# Problema del día 5, Validación del Orden de las Actulizaciones del manual de seguridad para el trineo

## Descripción del problema

Los elfos del Polo Norte necesitan asegurarse de que las actualizaciones del manual de seguridad para el trineo se impriman en un orden específico. Esto se debe a que ciertas páginas deben aparecer antes que otras según un conjunto de reglas de precedencia. Si estas reglas no se cumplen, las actualizaciones podrían ser incorrectas, lo que podría tener graves consecuencias.

El problema consiste en determinar qué actualizaciones cumplen con las reglas de precedencia y calcular la suma de los números centrales de las actualizaciones válidas.

## Entrada

El problema se divide en dos partes:

1. **Reglas de precedencia:**
   Cada regla está en el formato `A|B`, lo que significa que si ambos números, `A` e `B`, están presentes en una actualización, `A` debe aparecer antes que `B`.

2. **Actualizaciones:**
   Cada actualización es una secuencia de números separados por comas, representando el orden en el que se imprimirán las páginas.

La entrada termina con la palabra `fin` para ambas secciones.

### Ejemplo de Entrada:

```
47|53
97|13
97|61
97|47
75|29
fin

75,47,61,53,29
97,61,53,29,13
fin
```

## Salida

Lo que nos interesa calcular principalmente es:

1. Qué actualizaciones cumplen con las reglas de precedencia.
2. La suma de los números centrales de las actualizaciones válidas.

### Ejemplo de Salida:

```
La suma de los números del medio de las secuencias válidas es: 87
```

## Solución

Nuestra solución para resolver el problema anterior implementa los siguientes pasos:

### 1. Representación de las Reglas de Precedencia

En primer lugar, las reglas las almacenamos en un grafo dirigido donde:
- Cada nodo representa un número de página.
- Y también tiene una arista de `A` a `B`, que significa que `A` debe preceder a `B`.

### 2. Validación de que las Actualizaciones sean correctas

Para verificar si una actualización cumple con las reglas:
- Se recorren los pares consecutivos de la secuencia, es decir `a = i`y `b = ì+1`.
- Se verifica si para cada par `(a, b)` existe una arista de `a` a `b` en el grafo.
- Si alguno de los pares no cumple, la secuencia es inválida y se devuelve false.Y si se cumple se duelve true.

### 3. Cálculo del Valor Central

Para cada actualización válida:
- Se selecciona el número en la posición de en medio de la secuancia es decir `medio = secuencia[secuenzia.size()/2].
- Este valor se suma a la variable global suma.

### 4. Y por último liberamos los recursos utilizados

Al finalizar la ejecucción, se libera la memoria asignada para los nodos del grafo.


## Conclusión

El programa garantiza que las actualizaciones se validen correctamente de acuerdo con las reglas de precedencia, y calcula la suma de los números centrales de las secuencias válidas. Esto asegura que los manuales de seguridad se impriman en el orden adecuado, contribuyendo a la seguridad del trineo.

